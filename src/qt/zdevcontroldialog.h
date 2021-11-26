// Copyright (c) 2017-2020 The PIVX developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZDEVCONTROLDIALOG_H
#define ZDEVCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zdev/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class zDEVControlDialog;
}

class CzDEVControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CzDEVControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CzDEVControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CzDEVControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class zDEVControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit zDEVControlDialog(QWidget *parent);
    ~zDEVControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::zDEVControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CzDEVControlWidgetItem;

private Q_SLOTS:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZDEVCONTROLDIALOG_H
