bool MainWindow::getFiles(const QString &path, QVector<QString>& files)
{
	QDir dir(path);
	if (!dir.exists()) {
		QMessageBox::about(this,"","路径错误");
		return false;
	}
	dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
	dir.setSorting(QDir::DirsFirst);

	QFileInfoList list = dir.entryInfoList();
	if (list.size() < 1) return false;
	int i = 0;

	do {
		QFileInfo info = list[i];
		bool d = info.isDir();
		if (d) {
			getFiles(info.filePath(), files);
		}
		else {
			files.push_back(info.filePath());//+info.fileName()
		}
		i++;
	} while (i < list.size());

	return true;
}
