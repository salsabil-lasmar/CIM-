#include "installsoftwindow.h"

InstallSoftWindow::InstallSoftWindow(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant InstallSoftWindow::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex InstallSoftWindow::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex InstallSoftWindow::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int InstallSoftWindow::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int InstallSoftWindow::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant InstallSoftWindow::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
