// Copyright (c) 2019 The PIVX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "qt/dev/settings/settingsfaqwidget.h"
#include "qt/dev/qtutils.h"
#include "qt/dev/settings/forms/ui_settingsfaqwidget.h"
#include <QDesktopServices>
#include <QMetaObject>
#include <QScrollBar>

SettingsFaqWidget::SettingsFaqWidget(DEVGUI* parent) : QDialog(parent),
                                                       ui(new Ui::SettingsFaqWidget)
{
    ui->setupUi(this);

    this->setStyleSheet(parent->styleSheet());

    ui->labelTitle->setText(tr("Frequently Asked Questions"));
    ui->labelWebLink->setText(tr("You can read more here"));
#ifdef Q_OS_MAC
    ui->container->load("://bg-welcome");
    setCssProperty(ui->container, "container-welcome-no-image");
#else
    setCssProperty(ui->container, "container-welcome");
#endif
    setCssProperty(ui->labelTitle, "text-title-faq");
    setCssProperty(ui->labelWebLink, "text-content-white");

    // Content
    setCssProperty({
                       ui->labelNumber1,
                       ui->labelNumber2,
                       ui->labelNumber3,
                       ui->labelNumber4,
                       ui->labelNumber5,
                       ui->labelNumber6,
                   },
        "container-number-faq");

    setCssProperty({
                       ui->labelSubtitle1,
                       ui->labelSubtitle2,
                       ui->labelSubtitle3,
                       ui->labelSubtitle4,
                       ui->labelSubtitle5,
                       ui->labelSubtitle6,
                   },
        "text-subtitle-faq");


    setCssProperty({
                       ui->labelContent1,
                       ui->labelContent2,
                       ui->labelContent3,
                       ui->labelContent4,
                       ui->labelContent5,
                       ui->labelContent6,
                   },
        "text-content-faq");


    setCssProperty({
                       ui->pushButtonFaq1,
                       ui->pushButtonFaq2,
                       ui->pushButtonFaq3,
                       ui->pushButtonFaq4,
                       ui->pushButtonFaq5,
                       ui->pushButtonFaq6,
                   },
        "btn-faq-options");

    ui->labelContent1->setOpenExternalLinks(true);
    ui->labelContent1->setOpenExternalLinks(true);
    ui->labelContent3->setOpenExternalLinks(true);
    ui->labelContent4->setOpenExternalLinks(true);
    ui->labelContent5->setOpenExternalLinks(true);
    ui->labelContent6->setOpenExternalLinks(true);

    // Exit button
    ui->pushButtonExit->setText(tr("Exit"));
    setCssProperty(ui->pushButtonExit, "btn-faq-exit");

    // Web Link
    // ui->pushButtonWebLink->setText("https://deviantcoin.io/");
    setCssProperty(ui->pushButtonWebLink, "btn-faq-web");
    setCssProperty(ui->containerButtons, "container-faq-buttons");

    // Buttons
    connect(ui->pushButtonExit, &QPushButton::clicked, this, &SettingsFaqWidget::close);
    connect(ui->pushButtonFaq1, &QPushButton::clicked, this, &SettingsFaqWidget::onFaq1Clicked);
    connect(ui->pushButtonFaq2, &QPushButton::clicked, this, &SettingsFaqWidget::onFaq2Clicked);
    connect(ui->pushButtonFaq3, &QPushButton::clicked, this, &SettingsFaqWidget::onFaq3Clicked);
    connect(ui->pushButtonFaq4, &QPushButton::clicked, this, &SettingsFaqWidget::onFaq4Clicked);
    connect(ui->pushButtonFaq5, &QPushButton::clicked, this, &SettingsFaqWidget::onFaq5Clicked);
    connect(ui->pushButtonFaq6, &QPushButton::clicked, this, &SettingsFaqWidget::onFaq6Clicked);
    connect(ui->pushButtonWebLink, &QPushButton::clicked, this, &SettingsFaqWidget::onButtonWebLinkClicked);

    if (parent)
        connect(parent, &DEVGUI::windowResizeEvent, this, &SettingsFaqWidget::windowResizeEvent);
}

void SettingsFaqWidget::showEvent(QShowEvent* event)
{
    if (pos != 0) {
        QPushButton* btn = getButtons()[pos - 1];
        QMetaObject::invokeMethod(btn, "setChecked", Qt::QueuedConnection, Q_ARG(bool, true));
        QMetaObject::invokeMethod(btn, "clicked", Qt::QueuedConnection);
    }
}

void SettingsFaqWidget::setSection(int num)
{
    if (num < 1 || num > 10)
        return;
    pos = num;
}

void SettingsFaqWidget::onFaq1Clicked()
{
    ui->scrollAreaFaq->verticalScrollBar()->setValue(ui->widgetFaq1->y());
}

void SettingsFaqWidget::onFaq2Clicked()
{
    ui->scrollAreaFaq->verticalScrollBar()->setValue(ui->widgetFaq2->y());
}

void SettingsFaqWidget::onFaq3Clicked()
{
    ui->scrollAreaFaq->verticalScrollBar()->setValue(ui->widgetFaq3->y());
}

void SettingsFaqWidget::onFaq4Clicked()
{
    ui->scrollAreaFaq->verticalScrollBar()->setValue(ui->widgetFaq4->y());
}

void SettingsFaqWidget::onFaq5Clicked()
{
    ui->scrollAreaFaq->verticalScrollBar()->setValue(ui->widgetFaq5->y());
}

void SettingsFaqWidget::onFaq6Clicked()
{
    ui->scrollAreaFaq->verticalScrollBar()->setValue(ui->widgetFaq6->y());
}

void SettingsFaqWidget::onButtonWebLinkClicked()
{
    QUrl url(ui->pushButtonWebLink->text());
    QDesktopServices::openUrl(url);
}

void SettingsFaqWidget::windowResizeEvent(QResizeEvent* event)
{
    QWidget* w = qobject_cast<QWidget*>(parent());
    this->resize(w->width(), w->height());
    this->move(QPoint(0, 0));
}

std::vector<QPushButton*> SettingsFaqWidget::getButtons()
{
    return {
        ui->pushButtonFaq1,
        ui->pushButtonFaq2,
        ui->pushButtonFaq3,
        ui->pushButtonFaq4,
        ui->pushButtonFaq5,
        ui->pushButtonFaq6};
}

SettingsFaqWidget::~SettingsFaqWidget()
{
    delete ui;
}
