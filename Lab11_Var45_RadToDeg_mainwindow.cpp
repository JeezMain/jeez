
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btn_calc, &QPushButton::clicked, this, &MainWindow::on_calc_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calc_clicked()
{
    bool ok;
    double alpha_rad = ui->spin_rad->value();

    if (alpha_rad >= 0 && alpha_rad < 2 * 3.14) {
        double alpha_deg = alpha_rad * 180 / 3.14;
        ui->lbl_result->setText(QString::number(alpha_deg, 'f', 2) + " градусів");
    } else {
        QMessageBox::warning(this, "Помилка", "Значення кута має бути в межах [0, 2π)");
        ui->lbl_result->setText("");
    }
}
