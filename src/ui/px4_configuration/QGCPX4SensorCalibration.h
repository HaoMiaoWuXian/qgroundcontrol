#ifndef QGCPX4SENSORCALIBRATION_H
#define QGCPX4SENSORCALIBRATION_H

#include <QWidget>
#include <UASInterface.h>
#include <QAction>

namespace Ui {
class QGCPX4SensorCalibration;
}

class QGCPX4SensorCalibration : public QWidget
{
    Q_OBJECT
    
public:
    explicit QGCPX4SensorCalibration(QWidget *parent = 0);
    ~QGCPX4SensorCalibration();

public slots:
    /**
     * @brief Set currently active UAS
     * @param uas the current active UAS
     */
    void setActiveUAS(UASInterface* uas);
    /**
     * @brief Handle text message from current active UAS
     * @param uasid
     * @param componentid
     * @param severity
     * @param text
     */
    void handleTextMessage(int uasid, int componentid, int severity, QString text);

    void gyroButtonClicked();
    void magButtonClicked();
    void accelButtonClicked();

    /**
     * @brief Hand context menu event
     * @param event
     */
    virtual void contextMenuEvent(QContextMenuEvent* event);

    void setAutopilotOrientation(int index);
    void setGpsOrientation(int index);
    void parameterChanged(int uas, int component, QString parameterName, QVariant value);

protected slots:

    void setInstructionImage(const QString &path);

    void setAutopilotImage(const QString &path);

    void setGpsImage(const int index);

    void setAutopilotImage(const int index);

    void setGpsImage(const QString &path);

protected:
    UASInterface* activeUAS;
    QAction* clearAction;
    QPixmap instructionIcon;
    QPixmap autopilotIcon;
    QPixmap gpsIcon;
    bool accelStarted;
    bool accelDone[6];
    bool gyroStarted;
    bool magStarted;
    QStringList accelAxes;

    virtual void resizeEvent(QResizeEvent* event);

    void setMagCalibrated(bool calibrated);
    void setGyroCalibrated(bool calibrated);
    void setAccelCalibrated(bool calibrated);
    
private:
    Ui::QGCPX4SensorCalibration *ui;
};

#endif // QGCPX4SENSORCALIBRATION_H
