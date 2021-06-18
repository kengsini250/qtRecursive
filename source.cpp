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


//获取图片路径
void getFiles(string path, vector<string>& files) {
	//文件句柄	
	intptr_t hFile = 0;
	//文件信息	
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{			//如果是目录,迭代之			
					//如果不是,加入列表			
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}


//获取文件名
string GetImageName(string path)
{
	/*
	   C:\\xxx\\xxx\\ xxx .bmp
	                |     |
	              first   |
			     last
	*/
	string ImageName;
	int first = path.find_last_of("\\");
	int last = path.find_first_of(".");
	if (first != -1)
	{
		ImageName = path.substr(first + 1, last - first - 1);
	}
	return ImageName;
}
