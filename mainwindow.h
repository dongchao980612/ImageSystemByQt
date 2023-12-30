#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextCodec>
#include <QImage>
#include <QLabel>
using namespace cv;
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Button_exit_clicked();

    void on_Button_open_clicked();

    void on_Button_save_clicked();

    void on_actionRGB2grey_triggered();

    void on_action_histogram_triggered();

    void on_action_gray_transform_liner_triggered();

    void on_action_gray_transform_log_triggered();

    void on_action_gray_transform_gamma_triggered();

    void on_action_erode_triggered();

    void on_action_dilate_triggered();

    void on_action_area_growth_triggered();

    void on_action_edge_Sobel_triggered();

    void on_action_edge_Canny_triggered();

    void on_action_threshold_seg_fixed_threshold_triggered();

    void on_action_threshold_seg_unfixed_threshold_triggered();

    void on_action_mean_filtering_triggered();

    void on_action_median_filtering_triggered();

    void on_action_gaussian_filtering_triggered();

private:
    Ui::MainWindow *ui;
    Mat m_rgb;
    Mat m_grey;
    QImage q_rgb, q_grey;


    QImage Mat2QImage(const Mat &mat);
    QImage ImageCenter(const QImage image);
};
#endif // MAINWINDOW_H
