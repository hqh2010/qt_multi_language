#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_Translator = new QTranslator(this);
    isChinese = true;
}

MainWindow::~MainWindow()
{
    delete m_Translator;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    bool ret = false;
    if (isChinese) {
        // qm的路径必须找得到，控件的可翻译属性必须 勾选上
        // ret = m_Translator->load("/home/test/Desktop/qmultilan_demo/qt-multi-lan/translations/lan_cn.qm");
        ret = m_Translator->load(":/translations/lan_cn.qm");
    } else {
        ret = m_Translator->load(":/translations/lan_en.qm");
    }
    qInfo() << "on_pushButton_clicked load config ret:" << ret;
    isChinese = !isChinese;
    qApp->installTranslator(m_Translator);
    // ui->label->setText(tr("Hello world"));
    // ui->pushButton->setText(tr("switch language"));
    ui->retranslateUi(this);
    qInfo() << "on_pushButton_clicked switch language " << isChinese;
}
