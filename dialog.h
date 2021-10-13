#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSettings>
#include <QSerialPort>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog( QWidget *parent = nullptr );
    ~Dialog();

private:
    void getSerialNumber(void);
    void initSerial(void);
    void openSerial(void);
    void closeSerial(void);
    void initSetting(void);
    void initConnect(void);
    int parityBitStrToInt(QString s);
    int stopBitStrToInt(QString s);
    int flowControlStrToInt(QString s);
    void sendBytes(const QByteArray);


private:
    Ui::Dialog *ui;
    QSerialPort *serial1;

    QTimer *m_timerGetSerialNumber; /* 定时器 */

    QStringList m_serialNameList;
    QStringList *m_serialBaudRateList;
    QStringList *m_serialDataBitList;
    QStringList *m_serialParityList;
    QStringList	*m_serialStopBit;
    QStringList *m_SerialFlowControl;

    QString		m_settingFileName;          /* 配置文件名 */
    QSettings	*m_settingFileObj;          /* 配置文件 */

    QByteArray m_txBuffer;

    bool m_serialIsOpen;

private slots:
    void m_slotTimerGetSerialNumber(void);
    void m_slotCbSerialNumberActivated(int index);
    void m_slotCbBautActivated( int index );
    void m_slotCbDataBitActivated( int index );
    void m_slotCbParityBitActivated(int index);
    void m_slotCbStopBitActivated(int index);
    void m_slotCbFlowControlActivated(int index);
    void m_slotOpenSerial(bool);
    void m_slotOpenLED(bool);

};
#endif /* DIALOG_H */
