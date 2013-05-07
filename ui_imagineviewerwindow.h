/********************************************************************************
** Form generated from reading UI file 'imagineviewerwindow.ui'
**
** Created: Mon Apr 22 18:29:46 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGINEVIEWERWINDOW_H
#define UI_IMAGINEVIEWERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImagineViewerWindow
{
public:
    QAction *actionAbrir;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *Image;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImagineViewerWindow)
    {
        if (ImagineViewerWindow->objectName().isEmpty())
            ImagineViewerWindow->setObjectName(QString::fromUtf8("ImagineViewerWindow"));
        ImagineViewerWindow->resize(400, 300);
        actionAbrir = new QAction(ImagineViewerWindow);
        actionAbrir->setObjectName(QString::fromUtf8("actionAbrir"));
        centralWidget = new QWidget(ImagineViewerWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Image = new QLabel(centralWidget);
        Image->setObjectName(QString::fromUtf8("Image"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Image->sizePolicy().hasHeightForWidth());
        Image->setSizePolicy(sizePolicy);
        Image->setScaledContents(true);

        verticalLayout->addWidget(Image);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        ImagineViewerWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImagineViewerWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 20));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        ImagineViewerWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImagineViewerWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ImagineViewerWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ImagineViewerWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ImagineViewerWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuArchivo->addAction(actionAbrir);

        retranslateUi(ImagineViewerWindow);

        QMetaObject::connectSlotsByName(ImagineViewerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ImagineViewerWindow)
    {
        ImagineViewerWindow->setWindowTitle(QApplication::translate("ImagineViewerWindow", "ImagineViewerWindow", 0, QApplication::UnicodeUTF8));
        actionAbrir->setText(QApplication::translate("ImagineViewerWindow", "Abrir", 0, QApplication::UnicodeUTF8));
        Image->setText(QApplication::translate("ImagineViewerWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ImagineViewerWindow", "salir", 0, QApplication::UnicodeUTF8));
        menuArchivo->setTitle(QApplication::translate("ImagineViewerWindow", "Archivo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImagineViewerWindow: public Ui_ImagineViewerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGINEVIEWERWINDOW_H
