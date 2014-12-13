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

#ifndef PARALLELHANDLE_H
#define PARALLELHANDLE_H

#include <opencv2/opencv.hpp>
#include <queue>

#include "openglwindow.h"
#include "capturecamera.h"

#include <QtCore>
#include <QTime>
#include <QApplication>


using namespace glm;

class worker : public QObject
{
  Q_OBJECT

    volatile bool running;

    CaptureCamera *cam;
    QMutex mutex;
    QWaitCondition *line;

    std::vector<Line> result;

public:
    explicit worker(QWaitCondition *q, CaptureCamera *cam,QObject *parent = 0);
    ~worker(){do_Work(); emit finished();}

signals:
    void finished();
    void ResultReady(std::vector<Line> lines);

public slots:
  void StopWork();
  void StartWork();

private slots:
  void do_Work();

private:

};

#endif // PARALLELHANDLE_H
