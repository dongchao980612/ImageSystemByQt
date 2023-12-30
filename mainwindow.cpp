#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_rgb->setText("");
    ui->label_grey->setText("");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Button_exit_clicked()
{
    this->close();
}

void MainWindow::on_Button_open_clicked()
{
    // 显示打开文件对话框
    QString filter = tr("Images (*.png  *.jpg)");
    QString dlgTitle = "选择一张图片文件";
    QString curPath = QDir::currentPath() ;
    QString imagePath = QFileDialog::getOpenFileName(nullptr, dlgTitle, curPath, filter);
    // 判断用户是否选择了文件
    if (imagePath.isEmpty())
    {
        QMessageBox::critical(nullptr, "错误", "用户取消了文件选择", QMessageBox::Ok);
        return ;
    }
    QTextCodec *code = QTextCodec::codecForName("gb2312");
    string name = code->fromUnicode(imagePath).data();

    m_rgb = cv::imread(name);
    if (m_rgb.empty())
    {
        qDebug()  << "无法加载图片!" << endl;
        return;
    }

    q_rgb = Mat2QImage(m_rgb);
    // qDebug() << q_rgb.size();

    q_rgb = ImageCenter(q_rgb);
    // qDebug() << q_rgb.size();

    ui->label_rgb->setPixmap(QPixmap::fromImage(q_rgb));
    ui->label_rgb->setAlignment(Qt::AlignCenter);
}


//图片居中显示,图片大小与label大小相适应
QImage MainWindow::ImageCenter(QImage qimage)
{
    QImage image;
    QSize imageSize = qimage.size();


    double dWidthRatio = 1.0 * imageSize.width() / ui->widget_show_rgb->width();
    double dHeightRatio = 1.0 * imageSize.height() / ui->widget_show_rgb->height();
    cout << dWidthRatio << "\t" << dHeightRatio << endl;
    if (dWidthRatio > dHeightRatio)
    {
        image = qimage.scaledToWidth(ui->widget_show_rgb->width());
    }
    else
    {
        image = qimage.scaledToHeight(ui->widget_show_rgb->height());
    }
    return image;
}


//将cv::Mat转换为QImage
QImage MainWindow::Mat2QImage(const Mat &mat)
{
    const unsigned char *data = mat.data;

    int width = mat.cols;
    int height = mat.rows;
    int bytesPerLine = static_cast<int>(mat.step);
    switch(mat.type())
    {
        //8 bit , ARGB
        case CV_8UC4:
            {
                QImage image(data, width, height, bytesPerLine, QImage::Format_ARGB32);
                return image;
            }

        //8 bit BGR
        case CV_8UC3:
            {
                QImage image(data, width, height, bytesPerLine, QImage::Format_RGB888);
                //swap blue and red channel
                return image.rgbSwapped();
            }

        //8 bit Gray shale
        case CV_8UC1:
            {
                QImage image(data, width, height, bytesPerLine, QImage::Format_Grayscale8);
                return image;
            }

        //
        default:
            {
                throw invalid_argument("Image format not supported");
                return QImage();
            }
    }
}



void MainWindow::on_Button_save_clicked()
{
    if(!q_grey.isNull())
    {
        QString filename = QFileDialog::getSaveFileName(this, tr("保存图片"), "",
                           tr("*.png;; *.jpg;; *.bmp;; *.tif;; *.GIF")); //选择路径
        if (filename.isEmpty())
        {
            return;
        }
        else
        {
            if (!(q_grey.save(filename))) //保存图像
            {
                QMessageBox::information(this, tr("图片保存成功！"), tr("图片保存失败！"));
                return;
            }
        }
    }
    else
    {
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
    }
}

void MainWindow::on_actionRGB2grey_triggered()
{

    cvtColor(m_rgb, m_grey, cv::COLOR_BGR2GRAY);
    q_grey = Mat2QImage(m_grey);
    q_grey = ImageCenter(q_grey);
    qDebug() << q_grey.size();
    ui->label_grey->setPixmap(QPixmap::fromImage(q_grey));
    ui->label_grey->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_action_histogram_triggered()
{

}

void MainWindow::on_action_gray_transform_liner_triggered()
{

}

void MainWindow::on_action_gray_transform_log_triggered()
{

}

void MainWindow::on_action_gray_transform_gamma_triggered()
{

}

void MainWindow::on_action_erode_triggered()
{

}

void MainWindow::on_action_dilate_triggered()
{

}

void MainWindow::on_action_area_growth_triggered()
{

}

void MainWindow::on_action_edge_Sobel_triggered()
{

}

void MainWindow::on_action_edge_Canny_triggered()
{

}

void MainWindow::on_action_threshold_seg_fixed_threshold_triggered()
{

}

void MainWindow::on_action_threshold_seg_unfixed_threshold_triggered()
{

}

void MainWindow::on_action_mean_filtering_triggered()
{

}

void MainWindow::on_action_median_filtering_triggered()
{

}

void MainWindow::on_action_gaussian_filtering_triggered()
{

}
