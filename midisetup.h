/*
MidyAX
*/

#ifndef MIDISETUP_H
#define MIDISETUP_H

#include "ui_midisetup.h"
#include <QDialog>
#include "MidyAX_types.h"

class MidiSetup : public QDialog
{
    Q_OBJECT

public:

    MidiSetup(QWidget *parent = 0);
    bool omniIsEnabled() const;

    int exec();
    void retranslateUi();
    void clearCombos();
    void addInputPortName(const QString& name, int index);
    void addOutputPortName(const QString& output, int index);

    void fillWidgetList(  QList<QComboBox *>  *WidgetList, QWidget *gridLayoutWidget, QString *widgetName );

    int getSelectedInputIndex(int MIDIControllerIndex );
    int getSelectedOutputIndex( int MIDIControllerIndex );
    int getCurrentInputIndex(int MIDIControllerIndex );
    int getCurrentOutputIndex( int MIDIControllerIndex );

    int getSelectedInputPortNumber( int comboIndex );
    int getSelectedOutputPortNumber( int comboIndex );
    int getCurrentInputPortNumber(int MIDIControllerIndex );
    int getCurrentOutputPortNumber( int MIDIControllerIndex );

    void setCurrentInputIndexByPortOutputPortNumber(int MIDIControllerIndex, int comboIndex);
    void setCurrentOutputIndexByPortOutputPortNumber( int MIDIControllerIndex, int comboIndex );


    void setFixedCCMIDIChannel( int MIDIControllerNumber, int MIDIChannel );
    void setAXEFXMIDIChannel( int MIDIControllerNumber, int MIDIChannel );
    void setFixedEffectBlockOBControlMIDIChannel( int MIDIControllerNumber, int MIDIChannel );
    void setFixedPageControlMIDIChannel( int MIDIControllerNumber, int MIDIChannel );
    int getFixedCCMIDIChannel( int MIDIControllerNumber );
    int getAXEFXMIDIChannel( int MIDIControllerNumber );
    int getFixedEffectBlockOBControlMIDIChannel( int MIDIControllerNumber );
    int getFixedPageControlMIDIChannel( int MIDIControllerNumber );

    void setFractProdName( QString cractProdName);

//    QString selectedInputName( int MIDIControllerIndex ) const;
//    QString selectedOutputName_AXEFX( int MIDIControllerIndex ) const;


private slots:
    void on_buttonBox_accepted();
    void onSBValueChanged( int arg1 );

private:
    Ui::MidiSetupClass ui;

    QList <QComboBox *> inputComboBox;
    QList <QComboBox *> outputComboBox;
    QList <QSpinBox *> sBparamChannel;
    QList <QSpinBox *> sBpageChannel;
    QList <QSpinBox *> sBAXEFXChannel;
    QList <QSpinBox *> sBEffectBlockOBChannel;

    //int m_currrentIndex[ MAX_NUMBER_FIXED_CC_MIDI_CONTROLLERS ];
    int m_currentINIndex[ MAX_NUMBER_FIXED_CC_MIDI_CONTROLLERS ];
    int m_currentOUTIndex[ MAX_NUMBER_FIXED_CC_MIDI_CONTROLLERS ];
    int m_fixedCCMIDIChannel[MAX_NUMBER_FIXED_CC_MIDI_CONTROLLERS];
    int m_fixedAXEFXMIDIChannel[MAX_NUMBER_FIXED_CC_MIDI_CONTROLLERS];
    int m_fixedEffectBlockOBControlMIDIChannel[MAX_NUMBER_FIXED_CC_MIDI_CONTROLLERS];
    int m_fixedPageControlMIDIChannel[MAX_NUMBER_FIXED_CC_MIDI_CONTROLLERS];
};

#endif /* MIDISETUP_H */
