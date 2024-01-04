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
        // 在新线程中执行监视任务
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
            // // 检查文件是否被修改，这里使用了简单的定时器来模拟检测
            QThread::sleep(1); // 每秒检测一次

        }

        emit finished();
    }
};


#endif // FILE_MODIFY_MONITER_H
