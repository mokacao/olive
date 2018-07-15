#ifndef SOURCETABLE_H
#define SOURCETABLE_H

#include <QTreeWidget>
#include <QTimer>
#include <QUndoCommand>

class Project;

class SourceTable : public QTreeWidget
{
    Q_OBJECT
public:
	SourceTable(QWidget* parent = 0);
protected:
    void mousePressEvent(QMouseEvent*);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
private:
    QTimer rename_timer;
    QTreeWidgetItem* editing_item;
private slots:
    void rename_interval();
    void item_click(QTreeWidgetItem* item, int column);
    void stop_rename_timer();
};

class MediaMove : public QUndoCommand {
public:
    MediaMove(SourceTable* s);
    QVector<QTreeWidgetItem*> items;
    QTreeWidgetItem* to;
    void undo();
    void redo();
private:
    QVector<QTreeWidgetItem*> froms;
    SourceTable* table;
};

#endif // SOURCETABLE_H
