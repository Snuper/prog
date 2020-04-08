using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Timers;
using System.IO;

namespace VP_4
{
    public partial class Form1 : Form
    {
        string tstring = "";
        public Form1()
        {
            InitializeComponent();
            FilterComboBox1.SelectedIndex = 0;

            foreach (var drive in DriveInfo.GetDrives())
            {
                try
                {
                    DriveComboBox1.Items.Add(drive.Name);
                }
                catch { }

                Console.WriteLine();
            }

            DriveComboBox1.SelectedIndex = 0;
            toolStripStatusLabel1.Text = "";
            toolStripStatusLabel2.Text = "";
            label5.Text = DateTime.Now.ToString("HH:mm:ss");
        }

        private void splitContainer1_Panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void DriveComboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            DirecotyListBox1.Path = DriveComboBox1.SelectedItem.ToString();
            tstring = DriveComboBox1.SelectedItem.ToString();

        }

        private void DirecotyListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            FileListBox1.Path = DirecotyListBox1.Path;
        }

        private void FileListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            System.IO.FileInfo file = new System.IO.FileInfo(FileListBox1.Path.ToString() + "\\" + FileListBox1.SelectedItem.ToString());
            long size = file.Length;

            toolStripStatusLabel1.Text = FileListBox1.Path.ToString();
            toolStripStatusLabel2.Text = FileListBox1.SelectedItem.ToString() + ", " + size + " байт";

            if (FileListBox1.SelectedItem.ToString().EndsWith(".jpg") || FileListBox1.SelectedItem.ToString().EndsWith(".JPG") || FileListBox1.SelectedItem.ToString().EndsWith(".PNG") || FileListBox1.SelectedItem.ToString().EndsWith(".png"))
            {
                if (Image.FromFile(FileListBox1.Path.ToString() + "\\" + FileListBox1.SelectedItem.ToString()).Width > 300 || Image.FromFile(FileListBox1.Path.ToString() + "\\" + FileListBox1.SelectedItem.ToString()).Height > 300)
                    pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
                else
                    pictureBox1.SizeMode = PictureBoxSizeMode.CenterImage;

                pictureBox1.Image = Image.FromFile(FileListBox1.Path.ToString() + "\\" + FileListBox1.SelectedItem.ToString());
            } else {
                pictureBox1.Image = null;
            }
        }

        private void menuStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void splitter2_SplitterMoved(object sender, SplitterEventArgs e)
        {

        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void обАвтореToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Филимонов Владислав\nПриходченко Иван\nИП-814");
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            label5.Text = DateTime.Now.ToString("HH:mm:ss");
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton1.Enabled == true)
            {
                timer1.Enabled = false;
            }
            else
            {
                timer1.Enabled = true;
            }

        }
    }
}
