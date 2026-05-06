//using Android.Graphics.Drawables;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_Four.Drawables
{
    public class CanvasDrawable : GraphicsView, IDrawable
    {
        public Point startPoint { get; set; } // mouse pressed
        public void setStartPoint(Point start) // setter for start point
        {
            startPoint = start;
        }
        public Point endPoint { get; set; } // mouse released 
        public void setEndPoint(Point end) // setter for end point
        {
            endPoint = end;
        }

        public enum shape { Rectangle, Ellipse, Line }
        public float Width { get; set; }
        public float Height { get; set; }
        public float Left { get; set; }
        public float Top { get; set; }
        public Color Fill { get; set; }
        public Color Stroke { get; set; }
        public int CurrentShape { get; set; }

        public List<Shapes> shapes = new List<Shapes>();

        public Microsoft.Maui.Graphics.IImage image;
        public void setImage(Microsoft.Maui.Graphics.IImage img)
        {
            if (img != null)
            {
                shapes.Clear(); // wipes all drawn shapes
                image = img;
                Invalidate();
            }
        }

        public void Draw(ICanvas canvas, RectF rect)
        {
            canvas.FillColor = Colors.White;
            canvas.FillRectangle(0, 0, rect.Width, rect.Height);

            if (image != null)
                canvas.DrawImage(image, 0, 0, rect.Width, rect.Height);

            foreach (var S in shapes)
            {
                Color.TryParse(S.StrokeColor, out Color stroke);
                Color.TryParse(S.FillColor, out Color fill);

                canvas.StrokeColor = stroke ?? Colors.Black;
                canvas.FillColor = fill ?? Colors.Transparent;
                canvas.StrokeSize = 3;

                float x = Math.Min(S.StartX, S.EndX);
                float y = Math.Min(S.StartY, S.EndY);
                float w = Math.Abs(S.EndX - S.StartX);
                float h = Math.Abs(S.EndY - S.StartY);

                if (S.ShapeType == 0) // use S.ShapeType, NOT CurrentShape
                    canvas.DrawLine(S.StartX, S.StartY, S.EndX, S.EndY);
                else if (S.ShapeType == 1)
                {
                    canvas.FillRectangle(x, y, w, h);
                    canvas.DrawRectangle(x, y, w, h);
                }
                else if (S.ShapeType == 2)
                {
                    canvas.FillEllipse(x, y, w, h);
                    canvas.DrawEllipse(x, y, w, h);
                }
            }
        }
        public CanvasDrawable()
        {
            Drawable = this;
        }

        public void SetStrokeColor(string s)
        {
            if (Color.TryParse(s, out Color parsedColor))
            {
                s = parsedColor.ToString();
                Stroke = parsedColor;
            }
        }
        public void SetFillColor(string s)
        {
            if (Color.TryParse(s, out Color parsedColor))
            {
                s = parsedColor.ToString();
                Fill = parsedColor;
            }
        }

        public void addShape()
        {
            shapes.Add
                (new Shapes
                {
                    ShapeType = CurrentShape,
                    StartX = (float)startPoint.X,
                    StartY = (float)startPoint.Y,
                    EndX = (float)endPoint.X,
                    EndY = (float)endPoint.Y,
                    StrokeColor = Stroke?.ToArgbHex() ?? "#000000",
                    FillColor = Fill?.ToArgbHex() ?? "#FFFFFF"
                });
        }
    }
}
