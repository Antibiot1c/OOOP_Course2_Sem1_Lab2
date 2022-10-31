#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "timer.h"
#include <QMainWindow>
#include <QToolBar>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimer>
#include <QTime>
#include <QLabel>
#include <QSplitter>
#include <QListWidget>
#include <QApplication>
#include <QFontDatabase>
#include <QList>
#include <QMessageBox>
#include <QTextEdit>
#include <QTimeEdit>
#include <QSound>
#include <QCheckBox>


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
    QTime temp;
private:

//Панель інструментів
//Toolbar
    QToolBar *toolbar;
    void setToolBar();
    QLabel *timelbl;
//Віджети головного вікна
//Main window widgets
    QLabel *mainTimerLbl;
    QTextEdit *mainTimerDescriptionLbl;
    QListWidget *listW;
    QList<Timer> timers;
//Додати вікно
//Add window
    QWidget *addWindow;
    QLabel *addTimerLbl;
    QLabel *addDescLbl;
    QLabel *addCountLbl;
    QTimeEdit *addTimeEdit;
    QTextEdit *addTextEdit;
    QTextEdit *addCountTextEdit;
    void addTimer();
//Вікно сигналу
//Signal Window
   QWidget *signalWindow;
   QLabel *timeoutLbl;
   QTextEdit *timeoutDescLbl;
   QPushButton *timeoutOKBtn;
   void timeoutWindow();
//Змінити вікно
//Edit Window
   QWidget *editWindow;
   QLabel *editTimeLbl;
   QLabel *editDescLbl;
   QTimeEdit *editTimeEdit;
   QTextEdit *editDescEdit;
   QPushButton *editTimerBtn;
   void toEditWindow();
   Timer buffer;
   QString tmp;
   int positionToEdit;
//Інформаційне вікно
//Info Window
   QWidget *settingsWindow;
   QLabel *doNotLbl;
   QCheckBox *doNotCheckBox;
   QPushButton *infoOKBtn;
   bool doNotDisturb;
//Для зупинки
//To Stop
   QVector<int> stoppedTimersPositions;

private slots:
    void addTimerBtnClicked();
    void stopTimer();
    void editTimerBtnClicked();
    void deleteTimer();
    void deleteAllTimers();
    void settingsWindowSlot();
    void infoOKBtnClicked();
private:
    void timerEvent(QTimerEvent *e);
    QList<Timer> getTimers();
    void timersSort();
    void updateTimersListW();

};
#endif // MAINWINDOW_H
