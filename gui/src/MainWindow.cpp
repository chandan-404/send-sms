#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkRequest>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), manager(new QNetworkAccessManager(this)) {
    ui->setupUi(this);
    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::sendSms);
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::onReply);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::sendSms() {
    QString to = ui->toField->text();
    QString msg = ui->msgField->toPlainText();

    QJsonObject json;
    json["to"] = to;
    json["msg"] = msg;

    QNetworkRequest req(QUrl("http://localhost:8080/send_sms"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    manager->post(req, QJsonDocument(json).toJson());
    ui->statusLabel->setText("Sending...");
}

void MainWindow::onReply(QNetworkReply *reply) {
    ui->statusLabel->setText(reply->error() == QNetworkReply::NoError
                             ? "Sent successfully!" : "Error sending SMS");
    reply->deleteLater();
}
