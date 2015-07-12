#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QToolButton>
#include <QScrollArea>

#include "widget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
//    MainWindow();
    ~MainWindow();

    void setTitle();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void newWindow();
    void cloneWindow();
    void newFile();
    void openFile();
    bool saveFile();
    void exportPDF();

    void zoomIn();
    void zoomOut();
    void zoomFitWidth();
    void zoomFitHeight();

    void pen();
    void ruler();
    void circle();
    void eraser();
    void select();
    void hand();

    void updateGUI();

    void modified();

    void toolbar();
    void statusbar();
    void fullscreen();
    void maximize();

    void black();
    void blue();
    void red();
    void green();
    void gray();
    void lightblue();
    void lightgreen();
    void magenta();
    void orange();
    void yellow();
    void white();

    void rotate();

    void about();

    void verticalScrolling();

    bool maybeSave();

private:
    // widgets
    Widget *mainWidget;
    QScrollArea* scrollArea;

    void createActions();
    void createToolBars();
    void createMenus();

    QLabel pageStatus;

    // actions
    QAction *newWindowAct;
    QAction *cloneWindowAct;
    QAction *newFileAct;
    QAction *openFileAct;
    QAction *saveFileAct;
    QAction *exportPDFAct;

    QAction *undoAct;
    QAction *redoAct;

    QAction *copyAct;
    QAction *pasteAct;
    QAction *cutAct;

    QAction *zoomInAct;
    QAction *zoomOutAct;
    QAction *zoomFitWidthAct;
    QAction *zoomFitHeightAct;

    QAction *pageFirstAct;
    QAction *pageLastAct;
    QAction *pageUpAct;
    QAction *pageDownAct;

    QAction *pageAddEndAct;
    QAction *pageAddBeginningAct;
    QAction *pageAddBeforeAct;
    QAction *pageAddAfterAct;

    QAction *pageRemoveAct;

    QAction *penAct;
    QAction *rulerAct;
    QAction *circleAct;
    QAction *eraserAct;
    QAction *selectAct;
    QAction *handAct;

    QAction *solidPatternAct;
    QAction *dashPatternAct;
    QAction *dashDotPatternAct;
    QAction *dotPatternAct;

    QAction *rotateAct;

    QAction *veryFinePenWidthAct;
    QAction *finePenWidthAct;
    QAction *mediumPenWidthAct;
    QAction *thickPenWidthAct;
    QAction *veryThickPenWidthAct;

    QAction *toolbarAct;
    QAction *statusbarAct;
    QAction *fullscreenAct;
    QAction *maximizeAct;

    // color actions
    QAction *blackAct;
    QAction *blueAct;
    QAction *redAct;
    QAction *greenAct;
    QAction *grayAct;
    QAction *lightblueAct;
    QAction *lightgreenAct;
    QAction *magentaAct;
    QAction *orangeAct;
    QAction *yellowAct;
    QAction *whiteAct;

    QAction *aboutAct;
    QAction *aboutQtAct;

    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QToolBar *viewToolBar;
    QToolBar *toolsToolBar;

    QToolButton *patternToolButton;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *pageMenu;
    QMenu *toolsMenu;
    QMenu *penWidthMenu;
    QMenu *patternMenu;
    QMenu *viewMenu;
    QMenu *helpMenu;

//    Document* currentDocument;

};


#endif // MAINWINDOW_H
