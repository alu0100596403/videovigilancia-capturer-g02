/********************************************************************************
** Form generated from reading UI file 'imagineviewerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGINEVIEWERWINDOW_H
#define UI_IMAGINEVIEWERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
            ImagineViewerWindow->setObjectName(QStringLiteral("ImagineViewerWindow"));
        ImagineViewerWindow->resize(400, 300);
        actionAbrir = new QAction(ImagineViewerWindow);
        actionAbrir->setObjectName(QStringLiteral("actionAbrir"));
        centralWidget = new QWidget(ImagineViewerWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Image = new QLabel(centralWidget);
        Image->setObjectName(QStringLiteral("Image"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Image->sizePolicy().hasHeightForWidth());
        Image->setSizePolicy(sizePolicy);
        Image->setScaledContents(true);

        verticalLayout->addWidget(Image);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        ImagineViewerWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImagineViewerWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 20));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        ImagineViewerWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImagineViewerWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ImagineViewerWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ImagineViewerWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ImagineViewerWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuArchivo->addAction(actionAbrir);

        retranslateUi(ImagineViewerWindow);

        QMetaObject::connectSlotsByName(ImagineViewerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ImagineViewerWindow)
    {
        ImagineViewerWindow->setWindowTitle(QApplication::translate("ImagineViewerWindow", "ImagineViewerWindow", 0));
        actionAbrir->setText(QApplication::translate("ImagineViewerWindow", "Abrir", 0));
        Image->setText(QApplication::translate("ImagineViewerWindow", "TextLabel", 0));
        pushButton->setText(QApplication::translate("ImagineViewerWindow", "salir", 0));
        menuArchivo->setTitle(QApplication::translate("ImagineViewerWindow", "Archivo", 0));
    } // retranslateUi

};

namespace Ui {
    class ImagineViewerWindow: public Ui_ImagineViewerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGINEVIEWERWINDOW_H
