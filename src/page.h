#ifndef PAGE_H
#define PAGE_H

#include <memory>

#include "element.h"

namespace MrDoc
{

class Page
{
public:
  Page();
  Page(const Page & page);
  Page &operator=(Page const & page);
  virtual ~Page() { }

  qreal width() const;
  qreal height() const;

  int pixelHeight(const qreal zoom, int devicePixelRatio = 1) const;
  int pixelWidth(const qreal zoom, int devicePixelRatio = 1) const;

  void setWidth(qreal width);
  void setHeight(qreal height);

  void setBackgroundColor(QColor backgroundColor);
  QColor backgroundColor(void) const;

  const QRectF &dirtyRect() const;
  void clearDirtyRect();

  bool changeFont(size_t elementNum, QFont font);

  bool changePenWidth(size_t strokeNum, qreal penWidth);
  bool changeStrokeColor(size_t strokeNum, QColor color);
  bool changeStrokePattern(size_t strokeNum, QVector<qreal> pattern);

  const std::vector<std::unique_ptr<Element> >& elements();

  std::vector<QPair<std::unique_ptr<Element>, size_t> > getElements(QPolygonF selectionPolygon);
  std::vector<QPair<std::unique_ptr<Element>, size_t> > removeElements(QPolygonF selectionPolygon);
  void removeElementAt(size_t i);
  void removeFirstElement();
  void removeLastElement();

  void insertElements(const std::vector<QPair<std::unique_ptr<Element>, size_t> >& elementsAndPositions);
  void insertElement(size_t position, std::unique_ptr<Element> element);

  void appendElement(std::unique_ptr<Element> element);
  void appendElements(const std::vector<std::unique_ptr<Element> >& elements);

  void prependElement(std::unique_ptr<Element> element);
  void prependElements(const std::vector<std::unique_ptr<Element> >& elements);

  /**
   * @brief paint
   * @param painter
   * @param zoom
   * @param region
   */
  virtual void paint(QPainter &painter, qreal zoom, QRectF region = QRect(0, 0, 0, 0));

protected:
  std::vector<std::unique_ptr<Element>> m_elements;

private:
  QColor m_backgroundColor;

  qreal m_width;  // post script units
  qreal m_height; // post script units

  QRectF m_dirtyRect;
};
}

#endif // PAGE_H
