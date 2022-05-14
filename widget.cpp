#include "widget.h"

const QString accessurl = "https://aip.baidubce.com/oauth/2.0/token?grant_type=client_credentials&client_id=%1&client_secret=%2&";
// 注意：使用自己的密钥对哦！
const char * client_id = "hZIViGUH1si8lbvRSmuYvMOv";
const char * client_secret = "GVGhfBXZ23CucSLv2d4cHZlVvhRbW1Yq";

//const QString faceUrl = "https://aip.baidubce.com/rest/2.0/face/v3/detect?access_token=%1";
const QString faceUrl = "https://aip.baidubce.com/rest/2.0/image-classify/v2/advanced_general?access_token=%1";

void on_pushButton_clicked(const QString& imgPath)
{


    QString img = Image::ImageToBase64(imgPath);

    QJsonObject post_data;
    QJsonDocument document;
    post_data.insert("image",img);
    post_data.insert("image_type","BASE64");
    post_data.insert("face_field","age,beauty,gender,expression");

    document.setObject(post_data);
    QByteArray post_param = document.toJson(QJsonDocument::Compact);


    QByteArray requestData = post_param;

    QString Url = QString(accessurl).arg(client_id).arg(client_secret);
    // 获取access_token
    QByteArray replyData;       // 保存回复的信息
    QMap<QString,QString> header;       // 头部
    header.insert(QString("Content-Type"),QString("application/json"));



    QString accesstoken;
    bool result = Http::post_sync(Url,header,requestData,replyData);
    if(result)
    {
        qDebug()<< QSslSocket::sslLibraryBuildVersionString();
        qDebug() << "assess_token hhh=====";
        QJsonObject obj = QJsonDocument::fromJson(replyData).object();
        accesstoken = obj.value("access_token").toString();
    }else{
        qDebug()<< QSslSocket::sslLibraryBuildVersionString();
        qDebug() << "error Assess_token hhh=========" <<result;
        return;
    }

    // 清除回复数据
    replyData.clear();


    QString imageUrl = faceUrl.arg(accesstoken);

    result = Http::post_sync(imageUrl,header,requestData,replyData);

    QJsonParseError json_error;
    // QJsonDocument document = QJsonDocument::fromJson(replyData, &json_error);
    document = QJsonDocument::fromJson(replyData,&json_error);
    if(json_error.error == QJsonParseError::NoError)
    {
        //判断是否是对象,然后开始解析数据
        if(document.isObject())
        {
            qDebug() << document;

        }
        qDebug() << "hhhhhhh+++=====================";
    }else{
        qDebug() << "error++++++++++++++++++++++=";
    }

}

using namespace QtAndroid;

#define CHECK_EXCEPTION() \
    if(env->ExceptionCheck())\
    {\
        qDebug() << "exception occured";\
        env->ExceptionClear();\
    }

class ResultReceiver: public QAndroidActivityResultReceiver
{
public:
    ResultReceiver(QString imagePath, QLabel *view)
        : m_imagePath(imagePath), m_imageView(view)
    {

    }

    void handleActivityResult(
            int receiverRequestCode,
            int resultCode,
            const QAndroidJniObject & data)
    {
        qDebug() << "handleActivityResult, requestCode - " << receiverRequestCode
                    << " resultCode - " << resultCode
                    << " data - " << data.toString();
        //RESULT_OK == -1
        if(resultCode == -1 && receiverRequestCode == 1)
        {
            qDebug() << "captured image to - " << m_imagePath;
            qDebug() << "captured image exist - " << QFile::exists(m_imagePath);
            m_imageView->setPixmap(QPixmap(m_imagePath));
            qDebug() << "+++++++++++++";
            on_pushButton_clicked(m_imagePath);
        }
    }

    QString m_imagePath;
    QLabel *m_imageView;
};

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QHBoxLayout *actInfoLayout = new QHBoxLayout();
    layout->addLayout(actInfoLayout);
    QPushButton *getBtn = new QPushButton("Get Info");
    connect(getBtn, SIGNAL(clicked()), this, SLOT(onGetActivityInfo()));
    actInfoLayout->addWidget(getBtn);
    m_activityInfo = new QLabel();
    m_activityInfo->setWordWrap(true);
    actInfoLayout->addWidget(m_activityInfo, 1);
    layout->addSpacing(2);

    QHBoxLayout *actionLayout = new QHBoxLayout();
    layout->addLayout(actionLayout);
    m_actionEdit = new QLineEdit("android.settings.SETTINGS");
    actionLayout->addWidget(m_actionEdit, 1);
    QPushButton *launchBtn = new QPushButton("Launch");
    connect(launchBtn, SIGNAL(clicked()), this, SLOT(onLaunch()));
    actionLayout->addWidget(launchBtn);
    layout->addSpacing(2);

    QPushButton *capture = new QPushButton("CaptureImage");
    connect(capture, SIGNAL(clicked()), this, SLOT(onCapture()));
    layout->addWidget(capture);
    m_capturedImage = new QLabel();
    m_capturedImage->setScaledContents(true);
    layout->addWidget(m_capturedImage, 1);
}

Widget::~Widget()
{

}

void Widget::onLaunch()
{
    QAndroidJniObject action = QAndroidJniObject::fromString(m_actionEdit->text());
    QAndroidJniObject intent("android/content/Intent","(Ljava/lang/String;)V", action.object<jstring>());
    startActivity(intent, 0);
    QAndroidJniEnvironment env;
    CHECK_EXCEPTION()
}

void Widget::onGetActivityInfo()
{
    QAndroidJniEnvironment env;

    QAndroidJniObject activity = androidActivity();
    QAndroidJniObject className =
            activity.callObjectMethod<jstring>("getLocalClassName");
    CHECK_EXCEPTION()
    QString name = className.toString();
    int index = name.lastIndexOf('.');
    if(index != -1)
    {
        name = name.mid(index + 1);
    }

    jint taskId = activity.callMethod<jint>("getTaskId");
    CHECK_EXCEPTION()
    jlong instanceCount = QAndroidJniObject::callStaticMethod<jlong>(
                "android/app/Activity",
                "getInstanceCount"
                );
    CHECK_EXCEPTION()

    QString activityInfo = QString("%1,task-%2,inst-%3")
            .arg(name).arg(taskId).arg(instanceCount);

    m_activityInfo->setText(activityInfo);
    m_activityInfo->adjustSize();
}

void Widget::onCapture()
{
    QAndroidJniEnvironment env;

    //constuct Intent for IMAGE_CAPTURE
    QAndroidJniObject action = QAndroidJniObject::fromString(
                "android.media.action.IMAGE_CAPTURE");
    QAndroidJniObject intent("android/content/Intent",
                             "(Ljava/lang/String;)V",
                             action.object<jstring>());

    //setup saved image location
    QString date = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
    QAndroidJniObject fileName = QAndroidJniObject::fromString(date + ".jpg");
    QAndroidJniObject savedDir = QAndroidJniObject::callStaticObjectMethod(
                "android/os/Environment",
                "getExternalStorageDirectory",
                "()Ljava/io/File;"
                );
    CHECK_EXCEPTION()
    qDebug() << "savedDir - " << savedDir.toString();
    QAndroidJniObject savedImageFile(
                "java/io/File",
                "(Ljava/io/File;Ljava/lang/String;)V",
                savedDir.object<jobject>(),
                fileName.object<jstring>());
    CHECK_EXCEPTION()
    qDebug() << "savedImageFile - " << savedImageFile.toString();
    QAndroidJniObject savedImageUri =
            QAndroidJniObject::callStaticObjectMethod(
                "android/net/Uri",
                "fromFile",
                "(Ljava/io/File;)Landroid/net/Uri;",
                savedImageFile.object<jobject>());
    CHECK_EXCEPTION()

    //tell IMAGE_CAPTURE the output location
    QAndroidJniObject mediaStoreExtraOutput
            = QAndroidJniObject::getStaticObjectField(
                "android/provider/MediaStore",
                "EXTRA_OUTPUT",
                "Ljava/lang/String;");
    CHECK_EXCEPTION()
    qDebug() << "MediaStore.EXTRA_OUTPUT - " << mediaStoreExtraOutput.toString();
    intent.callObjectMethod(
                "putExtra",
                "(Ljava/lang/String;Landroid/os/Parcelable;)Landroid/content/Intent;",
                mediaStoreExtraOutput.object<jstring>(),
                savedImageUri.object<jobject>());

    //launch activity for result
    ResultReceiver *resultReceiver =
            new ResultReceiver(savedImageFile.toString(), m_capturedImage);
    startActivity(intent, 1, resultReceiver);
    CHECK_EXCEPTION()



}


void Widget::sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

