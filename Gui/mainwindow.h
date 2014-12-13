/*
 *
 * Copyright (C) 2014  Miroslav Krajicek, Faculty of Informatics Masaryk University (https://github.com/kaajo).
 * All Rights Reserved.
 *
 * This file is part of WebCamCap.
 *
 * WebCamCap is free software: you can redistribute it and/or modify
 * it under the terms of the GNU LGPL version 3 as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * WebCamCap is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU LGPL version 3
 * along with WebCamCap. If not, see <http://www.gnu.org/licenses/lgpl-3.0.txt>.
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Gui/addproject.h"
#include "Gui/addcamera.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QCloseEvent>

#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    int index = 0;

    bool captureAnimation;
    bool record;
    Room *project;

    std::vector<std::vector<Line> > lines;
    std::vector<vec3> points;

    std::string logDestinationFolder;
    std::vector<std::string> recentProjects;
    QList <QAction*> recentProjectsQActions;

    QIcon playIcon, editIcon, saveIcon;


    //scroll area
    QWidget *scrollWidget;

protected:
    void closeEvent(QCloseEvent *event);

public:
    void keyPressEvent(QKeyEvent* e);
    void keyReleaseEvent(QKeyEvent* e);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    std::string operator<<(QString& string) {
        return string.toStdString();
    }

private slots:

    void on_newProject_triggered();

    void OpenRecentProjects();

    void on_openProject_triggered();

    void on_editProject_triggered();

    void on_saveProject_triggered();

    void on_nahravanie_clicked(bool checked);

    void on_playButton_pressed();

    void on_stopButton_pressed();

    void on_AnimationsTable_cellChanged(int row, int column);

    void on_AnimationsTable_cellClicked(int row, int column);

    void on_AddStructure_clicked();

    void on_LinesCheck_stateChanged(int arg1);

    void on_JointsCheck_stateChanged(int arg1);

    void on_BonesCheck_stateChanged(int arg1);

    void on_LivePipe_stateChanged(int arg1);

private:
    void on_Threshold_valueChanged(int value);

    void on_brightness_valueChanged(int value);


    void createRollOutMenu();
    bool searchForRecentProjects(std::string filestring);
    void saveLog();
    void loadLog();
    void setProjectStats();
    int NotSavedMessage();
    void handleMainWProject(Room *p);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
