using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Laba2
{
    public partial class Form1 : Form
    {
        bool _dragging = false;
        public Color CurrentColor = Color.Black;
        Point CurrentPoint;
        Point PrevPoint;
        Graphics g;
        public int red = 0, green = 0, blue = 0;
        int choosen_style = 1;

        public Form1()
        {
            InitializeComponent();
            var bitmap = new Bitmap(picDrawingSurface.Width, picDrawingSurface.Height);
            picDrawingSurface.BackColor = Color.White;
            picDrawingSurface.Image = bitmap;
            g = Graphics.FromImage(bitmap);
            comboBox1.SelectedIndex = 0;
        }

        private void choose_style()
        {
            choosen_style = comboBox1.SelectedIndex;
        }

        private void paint_simple()
        {
            Pen p = new Pen(CurrentColor, trackBar1.Value);

            if (solidToolStripMenuItem.Checked)
                p.DashStyle = DashStyle.Solid;
            if (dotToolStripMenuItem.Checked)
                p.DashStyle = DashStyle.Dot;
            if (dashDotDotToolStripMenuItem.Checked)
                p.DashStyle = DashStyle.DashDotDot;
            //g.DrawLine(p, new Point(0, 0), new Point(picDrawingSurface.Width, picDrawingSurface.Height)); //работают стили
            g.DrawLine(p, PrevPoint, CurrentPoint);
            picDrawingSurface.Invalidate();
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //g.Dispose
            picDrawingSurface.Image = null;
            var bitmap = new Bitmap(picDrawingSurface.Width, picDrawingSurface.Height);
            picDrawingSurface.BackColor = Color.White;
            picDrawingSurface.Image = bitmap;
            g = Graphics.FromImage(bitmap);
           
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog OP = new OpenFileDialog();
                       OP.Filter = "JPEG Image|*.jpg|Bitmap Image|*.bmp|GIF Image|*.gif|PNG Image|*.png";
            OP.Title = "Open an Image File";
            OP.FilterIndex = 1; //По умолчанию будет выбрано первое расширение *.jpg
            if (OP.ShowDialog() != DialogResult.Cancel)
                picDrawingSurface.Load(OP.FileName);

            picDrawingSurface.AutoSize = true;

        }

        private void saveToolStripMenuItem_Click_1(object sender, EventArgs e)
        {
            SaveFileDialog SaveDlg = new SaveFileDialog();
            SaveDlg.Filter = "JPEG Image|*.jpg|Bitmap Image|*.bmp|GIF Image|*.gif|PNG Image|*.png";
            SaveDlg.Title = "Save an Image File";
            SaveDlg.FilterIndex = 4;    //По умолчанию будет выбрано последнее расширение *.png

            SaveDlg.ShowDialog();
            if (SaveDlg.FileName != "")     //Если введено не пустое имя
            {
                System.IO.FileStream fs =
                   (System.IO.FileStream)SaveDlg.OpenFile();

                switch (SaveDlg.FilterIndex)
                {
                    case 1:
                        this.picDrawingSurface.Image.Save(fs, ImageFormat.Jpeg);
                        break;

                    case 2:
                        this.picDrawingSurface.Image.Save(fs, ImageFormat.Bmp);
                        break;

                    case 3:
                        this.picDrawingSurface.Image.Save(fs, ImageFormat.Gif);
                        break;

                    case 4:
                        this.picDrawingSurface.Image.Save(fs, ImageFormat.Png);
                        break;
                }

                fs.Close();
            }
        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            picDrawingSurface.Image = null;
            var bitmap = new Bitmap(picDrawingSurface.Width, picDrawingSurface.Height);
            picDrawingSurface.BackColor = Color.White;
            picDrawingSurface.Image = bitmap;
            g = Graphics.FromImage(bitmap);
        }

        private void toolStripButton3_Click(object sender, EventArgs e)
        {
            OpenFileDialog OP = new OpenFileDialog();
            OP.Filter = "JPEG Image|*.jpg|Bitmap Image|*.bmp|GIF Image|*.gif|PNG Image|*.png";
            OP.Title = "Open an Image File";
            OP.FilterIndex = 1; //По умолчанию будет выбрано первое расширение *.jpg
            if (OP.ShowDialog() != DialogResult.Cancel)
                picDrawingSurface.Load(OP.FileName);

            picDrawingSurface.AutoSize = true;

        }

        private void toolStripButton4_Click(object sender, EventArgs e)
        {
            SaveFileDialog SaveDlg = new SaveFileDialog();
            SaveDlg.Filter = "JPEG Image|*.jpg|Bitmap Image|*.bmp|GIF Image|*.gif|PNG Image|*.png";
            SaveDlg.Title = "Save an Image File";
            SaveDlg.FilterIndex = 4;    //По умолчанию будет выбрано последнее расширение *.png

            SaveDlg.ShowDialog();
            if (SaveDlg.FileName != "")     //Если введено не пустое имя
            {
                System.IO.FileStream fs =
                   (System.IO.FileStream)SaveDlg.OpenFile();

                switch (SaveDlg.FilterIndex)
                {
                    case 1:
                        this.picDrawingSurface.Image.Save(fs, ImageFormat.Jpeg);
                        break;

                    case 2:
                        this.picDrawingSurface.Image.Save(fs, ImageFormat.Bmp);
                        break;

                    case 3:
                        this.picDrawingSurface.Image.Save(fs, ImageFormat.Gif);
                        break;

                    case 4:
                        this.picDrawingSurface.Image.Save(fs, ImageFormat.Png);
                        break;
                }

                fs.Close();
            }
        }

        private void toolStripButton5_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Якунин Андрей и Парфенцов Семен ИП-814");
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Якунин Андрей и Парфенцов Семен ИП-814");
        }

        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                _dragging = true;
                CurrentPoint = e.Location;
                //_oldLocation = e.Location;
                //_currentPath = new GraphicsPath();
            }

        }

        private void picDrawingSurface_MouseUp(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                _dragging = false;
                //picDrawingSurface.Update();
                try
                {
                    //_currentPath.Dispose();
                }
                catch 
                {

                };
            }

        }

        private void picDrawingSurface_MouseMove(object sender, MouseEventArgs e)
        {
            lblX.Text = e.X.ToString();
            lblY.Text = e.Y.ToString();

            if (_dragging)
            {
                PrevPoint = CurrentPoint;
                CurrentPoint = e.Location;
                //pen
                paint_simple();
                //Graphics g = Graphics.FromImage(picDrawingSurface.Image);
               // _currentPath.AddLine(_oldLocation, e.Location);
                //g.DrawPath(_currentPen, _currentPath);
               // _oldLocation = e.Location;
                //g.Dispose();
                //picDrawingSurface.Invalidate();
            }

        }

        private void undoToolStripMenuItem_DoubleClick(object sender, EventArgs e)
        {
            Graphics g = Graphics.FromImage(picDrawingSurface.Image);
            //g.Clear(_bgColor);
            g.Dispose();
            picDrawingSurface.Invalidate();

        }

        private void toolStripButton6_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void colorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ColorDialog dlg = new ColorDialog();
            if (dlg.ShowDialog() == DialogResult.OK)
            {
                CurrentColor = dlg.Color;
            }        
        }

        private void solidToolStripMenuItem_Click(object sender, EventArgs e)
        {
            solidToolStripMenuItem.Checked = true;
            dotToolStripMenuItem.Checked = false;
            dashDotDotToolStripMenuItem.Checked = false;
            comboBox1.SelectedIndex = 0;
        }

        private void dotToolStripMenuItem_Click(object sender, EventArgs e)
        {
            dotToolStripMenuItem.Checked = true;
            solidToolStripMenuItem.Checked = false;
            dashDotDotToolStripMenuItem.Checked = false;
            comboBox1.SelectedIndex = 1;
        }

        private void dashDotDotToolStripMenuItem_Click(object sender, EventArgs e)
        {
            dashDotDotToolStripMenuItem.Checked = true;
            dotToolStripMenuItem.Checked = false;
            solidToolStripMenuItem.Checked = false;
            comboBox1.SelectedIndex = 2;
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            Form2 dlg = new Form2();
            dlg.Owner = this;
            dlg.ShowDialog();
        }

        public void myColorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 dlg = new Form2();
            dlg.Owner = this;
            dlg.ShowDialog();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBox1.SelectedIndex == 0)
            {
                solidToolStripMenuItem.Checked = true;
                dotToolStripMenuItem.Checked = false;
                dashDotDotToolStripMenuItem.Checked = false;
            }
            if (comboBox1.SelectedIndex == 1)
            {
                dotToolStripMenuItem.Checked = true;
                solidToolStripMenuItem.Checked = false;
                dashDotDotToolStripMenuItem.Checked = false;
            }
            if (comboBox1.SelectedIndex == 2)
            {
                dashDotDotToolStripMenuItem.Checked = true;
                dotToolStripMenuItem.Checked = false;
                solidToolStripMenuItem.Checked = false;
            }
        }

        bool clear_pen = false;

        private void erasebtn_Click(object sender, EventArgs e)
        {
            clear_pen = !clear_pen;
            if (clear_pen)
            {
                CurrentColor = Color.White;
                checkBox_erase.Checked = true;
            }
            else
            {
                CurrentColor = Color.Black;
                checkBox_erase.Checked = false;
            }
        }

        private void picDrawingSurface_DoubleClick_1(object sender, EventArgs e)
        {

        }

        private void helpToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void undoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Graphics g = Graphics.FromImage(picDrawingSurface.Image);
            g.Clear(Color.White);
            g.Dispose();
            picDrawingSurface.Invalidate();
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {

        }

        private void penToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void lblX_Click(object sender, EventArgs e)
        {

        }

        private void picDrawingSurface_Click(object sender, EventArgs e)
        {

        }
    }
}