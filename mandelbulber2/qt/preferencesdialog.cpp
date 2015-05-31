#include "preferencesdialog.h"
#include "ui_preferencesdialog.h"
#include <QtCore>
#include <QFileDialog>

cPreferencesDialog::cPreferencesDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::cPreferencesDialog)
{
  ui->setupUi(this);

	gMainInterface->ConnectSignalsForSlidersInWindow(this);
  gMainInterface->SynchronizeInterfaceWindow(this, gPar, cInterface::write);
}

cPreferencesDialog::~cPreferencesDialog()
{
  delete ui;
}

void cPreferencesDialog::on_buttonBox_accepted()
{
	gMainInterface->SynchronizeInterfaceWindow(this, gPar, cInterface::read);
}

void cPreferencesDialog::on_pushButton_select_image_path_clicked()
{
  QString dir = QFileDialog::getExistingDirectory(this, tr("Select default directory for images"), ui->text_default_image_path->text());
  if(dir.length() > 0)
  {
  	ui->text_default_image_path->setText(dir);
  }
}

void cPreferencesDialog::on_pushButton_select_settings_path_clicked()
{
  QString dir = QFileDialog::getExistingDirectory(this, tr("Select default directory for settings files"), ui->text_default_settings_path->text());
  if(dir.length() > 0)
  {
  	ui->text_default_settings_path->setText(dir);
  }
}

void cPreferencesDialog::on_pushButton_select_textures_path_clicked()
{
  QString dir = QFileDialog::getExistingDirectory(this, tr("Select default directory for textures"), ui->text_default_textures_path->text());
  if(dir.length() > 0)
  {
  	ui->text_default_textures_path->setText(dir);
  }
}
