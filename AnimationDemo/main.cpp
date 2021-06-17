#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>

using namespace  std;

class PhoneProduct {
public:
    virtual void showName() = 0;
};

class Galaxy : public PhoneProduct{
    public:
    void showName(){
        cout << "This Galaxy S5 " << endl;
    }
};

class Iphone : public PhoneProduct {
public:
    void showName(){
        cout << "this Iphone 6" << endl;
    }
};
class TabletProduct {
public:
    virtual void showName() = 0;
};

class SamsungTab : public TabletProduct{
public:
    void showName(){
        cout << " This samsung Tab E" << endl;
    }
};

class IPad : public TabletProduct{
public:
    void showName() {
        cout << " This IPad 4" << endl;
    }
};

class FactoryProduct {
public:
    virtual PhoneProduct* makePhone() = 0;
    virtual TabletProduct* makeTablet() = 0;
};

class SamsungFactory : public FactoryProduct{
public:
    PhoneProduct* makePhone(){
        return new Galaxy();
    }
    TabletProduct* makeTablet(){
        return new SamsungTab();
    }
};

class AppleFactory : public FactoryProduct{
public:
    PhoneProduct* makePhone(){
        return new Iphone();
    }
    TabletProduct* makeTablet(){
        return new IPad();
    }
};



int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);


    FactoryProduct *samsungProduct = new SamsungFactory();
    PhoneProduct *s_phone = samsungProduct->makePhone();
    TabletProduct *s_Tablet = samsungProduct->makeTablet();

    s_phone->showName();
    s_Tablet->showName();

    FactoryProduct *appleProduct = new AppleFactory();
    PhoneProduct *a_phone = appleProduct->makePhone();
    TabletProduct *a_Tablet = appleProduct->makeTablet();

    a_phone->showName();
    a_Tablet->showName();

    return app.exec();
}
