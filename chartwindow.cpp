#include "chartwindow.h"
#include "ui_chartwindow.h"

chartWindow::chartWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::chartWindow) {
  ui->setupUi(this);
}

QChartView *chartWindow::ShowTeacherView(QList<TeacherInfo> l) {

  QLineSeries *lineseries = new QLineSeries();
  QStringList categories;
  lineseries->setName("工资");
  for (int i = 0; i < l.size(); i++) {
    lineseries->append(i, l[i].getMoney().toInt());
    categories.append(l[i].getName());
  }
  QChart *chart = new QChart();
  QBarCategoryAxis *axis = new QBarCategoryAxis();
  chart->addSeries(lineseries);
  chart->createDefaultAxes();
  chart->legend()->setVisible(true);
  chart->legend()->setAlignment(Qt::AlignBottom);
  axis->append(categories);
  chart->setAxisX(axis);
  chart->setTitle("教师工资一览");
  QChartView *chartView = new QChartView(chart);
  chartView->setRenderHint(QPainter::Antialiasing);
  return chartView;
}

QChartView *chartWindow::ShowStudentBarSeries(QList<StudentInfo> l) {
  init();
  studentCourseSum->clear();
  QBarSet *chinese = new QBarSet("语文");
  QBarSet *mathematics = new QBarSet("数学");
  QBarSet *English = new QBarSet("英语");
  QBarSet *Physics = new QBarSet("物理");
  QBarSet *Chemistry = new QBarSet("化学");
  QBarSet *history = new QBarSet("历史");
  QBarSet *Geography = new QBarSet("地理");
  QBarSet *Politics = new QBarSet("政治");
  QBarSet *Biology = new QBarSet("生物");
  double (*re_str)(QString str) = [](QString str) {
    return str.replace(QRegExp("\\s+"), "").toDouble();
  };
  qDebug() << "QList<StudentInfo> l size ::: " << l.size();
  QStringList studentNameList;
  foreach (StudentInfo info, l) {
    chinese->append(re_str(info.getChinese()));
    mathematics->append(re_str(info.getMathematics()));
    English->append(re_str(info.getEnglish()));
    Physics->append(re_str(info.getPhysics()));
    Chemistry->append(re_str(info.getChemistry()));
    history->append(re_str(info.getHistory()));
    Geography->append(re_str(info.getGeography()));
    Politics->append(re_str(info.getPolitics()));
    Biology->append(re_str(info.getBiology()));
    studentNameList.append(info.getName());
  }
  Biology->setColor(QColor(28, 28, 28));
  Politics->setColor(QColor(72, 209, 204));
  Geography->setColor(QColor(139, 101, 8));
  history->setColor(QColor(205, 104, 57));
  Chemistry->setColor(QColor(208, 32, 144));
  studentCourseSum->append({chinese, mathematics, English, Physics, Chemistry,
                            history, Geography, Politics, Biology});
  studentCourseSum->setLabelsPosition(
      QAbstractBarSeries::
          LabelsInsideEnd); // 设置数据系列标签的位置于数据柱内测上方
  studentCourseSum->setLabelsVisible(true); // 设置显示数据系列标签
  QChart *chart2 = new QChart();
  chart2->addSeries(studentCourseSum);
  chart2->setTitle("学生成绩");
  chart2->setAnimationOptions(QChart::SeriesAnimations);
  QBarCategoryAxis *axis = new QBarCategoryAxis();
  axis->append(studentNameList);
  chart2->createDefaultAxes();
  chart2->setAxisX(axis, studentCourseSum);
  chart2->legend()->setVisible(true);
  chart2->legend()->setAlignment(Qt::AlignBottom);
  QChartView *chartView = new QChartView(chart2);
  chartView->setRenderHint(QPainter::Antialiasing);
  chartView->setHorizontalScrollBarPolicy(
      Qt::ScrollBarPolicy::ScrollBarAsNeeded);
  chartView->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);

  chartView->setResizeAnchor(QGraphicsView::AnchorUnderMouse);
  chartView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

  return chartView;
}

QChartView *chartWindow::ShowStudentChart(QList<StudentInfo> StudentInfoList) {
  init();
  series->clear();
  //  chart1->removeAllSeries();
  double sum = 0.0, boyNum = 0.0, girlNum = 0.0, boy = 0,
         num = StudentInfoList.size(), girl = 0;
  foreach (StudentInfo s, StudentInfoList) {
    if (s.getSex().compare("女") == 0) {
      girl++;
    }
    if (s.getSex().compare("男") == 0) {
      boy++;
    }
    sum += s.getSum().replace(QRegExp("\\s+"), "").toDouble();
  }
  boyNum = (boy / num) * 100;
  girlNum = (girl / num) * 100;
  qDebug() << "男生占" + QString::number(boyNum) + "%" << boyNum;
  qDebug() << "女生占" + QString::number(girlNum) + "%" << girlNum;
  series->append("男生占" + QString::number(boyNum) + "%", boyNum);
  series->append("女生占" + QString::number(girlNum) + "%", girlNum);
  series->setLabelsVisible(true);
  series->setHoleSize(0.35);
  series->slices().at(0)->setColor(QColor(0, 255, 255));
  series->slices().at(1)->setColor(QColor(205, 38, 38));
  QChart *chart1 = new QChart();
  chart1->addSeries(series);
  chart1->setTitle("学校男女比例");
  //  return chart;
  QChartView *chartView = new QChartView(chart1);
  //  chartView->setChart(chart);
  chartView->setRenderHint(QPainter::Antialiasing);

  return chartView;
}

void chartWindow::init() {
  if (init_ok == 0) {
    series = new QPieSeries();
    init_ok++;
  } else if (courseSum_init_ok == 0) {
    studentCourseSum = new QBarSeries();
    courseSum_init_ok++;
  }
}

chartWindow::~chartWindow() { delete ui; }
