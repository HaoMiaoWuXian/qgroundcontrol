/*=====================================================================

PIXHAWK Micro Air Vehicle Flying Robotics Toolkit

(c) 2009, 2010 PIXHAWK PROJECT  <http://pixhawk.ethz.ch>

This file is part of the PIXHAWK project

    PIXHAWK is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    PIXHAWK is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with PIXHAWK. If not, see <http://www.gnu.org/licenses/>.

======================================================================*/

/**
 * @file
 *   @brief Definition of of Horizontal Situation Indicator class
 *
 *   @author Lorenz Meier <mavteam@student.ethz.ch>
 *
 */

#ifndef HSIDISPLAY_H
#define HSIDISPLAY_H

#include <QtGui/QWidget>
#include <QColor>
#include <QTimer>
#include <QMap>
#include <QPair>
#include <cmath>

#include "HDDisplay.h"

class HSIDisplay : public HDDisplay {
    Q_OBJECT
public:
    HSIDisplay(QWidget *parent = 0);
    // ~HSIDisplay();

public slots:
    void setActiveUAS(UASInterface* uas);
    void paintEvent(QPaintEvent * event);

protected slots:
    void paintDisplay();
    void drawGPS();
    void drawObjects();
    void drawBaseLines(float xRef, float yRef, float radius, float yaw, const QColor& color, QPainter* painter, bool solid);


protected:
    void updateSatellite(int uasid, int satid, float azimuth, float direction, float snr, bool used);
    static QColor getColorForSNR(float snr);

    /**
     * @brief Private data container class to be used within the HSI widget
     */
    class GPSSatellite
    {
    public:
        GPSSatellite(int id, float azimuth, float direction, float snr, bool used) :
            id(id),
            azimuth(azimuth),
            direction(direction),
            snr(snr),
            used(used)
        {

        }

        void update(int id, float azimuth, float direction, float snr, bool used)
        {
            this->id = id;
            this->azimuth = azimuth;
            this->direction = direction;
            this->snr = snr;
            this->used = used;
        }

        int id;
        float azimuth;
        float direction;
        float snr;
        bool used;

        friend class HSIDisplay;
    };

    QVector<GPSSatellite*> gpsSatellites;
    unsigned int satellitesUsed;

private:
};

#endif // HSIDISPLAY_H
