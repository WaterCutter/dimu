#ifndef FILE_MODIFY_MONITER_H
#define FILE_MODIFY_MONITER_H

#include <QCoreApplication>
#include <QThread>
#include <QDebug>

class FileWatcher : public QObject
{
    Q_OBJECT

public:
    explicit FileWatcher(const QString& filePath, QObject* parent = nullptr)
        : QObject(parent), m_filePath(filePath)
    {
    }

public slots:
    void startWatching()
    {
        // monitoring file modification event in new thread
        QThread* thread = new QThread();
        connect(thread, &QThread::started, this, &FileWatcher::watchFile);
        connect(this, &FileWatcher::finished, thread, &QThread::quit);
        connect(thread, &QThread::finished, thread, &QThread::deleteLater);
        moveToThread(thread);
        thread->start();
    }

signals:
    void finished();

private:
    QString m_filePath;

    void watchFile()
    {
        // 监视文件变化
        while (true)
        {
            // //
            QThread::sleep(1); // 每秒检测一次

        }

        emit finished();
    }
};


#endif // FILE_MODIFY_MONITER_H
