/***************************************************************************
                               qucslib.h
                              -----------
    begin                : Sat May 28 2005
    copyright            : (C) 2005 by Michael Margraf
    email                : michael.margraf@alumni.tu-berlin.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QUCSLIB_H
#define QUCSLIB_H

#include <qdialog.h>
#include <qfont.h>
#include <qstring.h>

class SymbolWidget;
class QTextEdit;
class QComboBox;
class QListBox;
class QVGroupBox;
class QVBoxLayout;
class QListBoxItem;


// Application settings.
struct tQucsSettings {
  int x, y, dx, dy;    // position and size of main window
  QFont font;          // font
  QString BitmapDir;   // pixmap directory
  QString LangDir;     // translation directory
  QString LibDir;      // library directory
};

extern tQucsSettings QucsSettings;


class QucsLib : public QDialog  {
   Q_OBJECT
public:
  QucsLib();
 ~QucsLib();

private slots:
  void slotAbout();
  void slotQuit();
  void slotHelp();
  void slotCopyToClipBoard();
  void slotShowModel();
  void slotSelectLibrary(int);
  void slotSearchComponent();
  void slotShowComponent(QListBoxItem*);

private:
  void closeEvent(QCloseEvent*);

  SymbolWidget *Symbol;
  QVGroupBox   *CompGroup;
  QComboBox    *Library;
  QListBox     *CompList;
  QTextEdit    *CompDescr;
  QVBoxLayout  *all;
  QString       LibraryString, ModelString;
};

#endif /* QUCSLIB_H */