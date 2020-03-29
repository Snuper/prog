using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Laba2
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
            hScrollBar1.Tag = numericUpDown1;
            hScrollBar2.Tag = numericUpDown2;
            hScrollBar3.Tag = numericUpDown3;

            numericUpDown1.Tag = hScrollBar1;
            numericUpDown2.Tag = hScrollBar2;
            numericUpDown3.Tag = hScrollBar3;

        }

        private void UpdateColor()
        {
            pictureBox1.BackColor = Color.FromArgb(255, hScrollBar1.Value, hScrollBar2.Value, hScrollBar3.Value);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form1 main = this.Owner as Form1;
            if (main != null)
            {
                main.CurrentColor = Color.FromArgb(255, hScrollBar1.Value, hScrollBar2.Value, hScrollBar3.Value);
            }
            this.Close();
        }

        private void hScrollBar1_ValueChanged(object sender, EventArgs e)
        {
            //hScrollBar1.Value = (int)numericUpDown1.Value;
            numericUpDown1.Value = (int)hScrollBar1.Value;
            /*NumericUpDown numericUpDown = (NumericUpDown)sender;
            ScrollBar scrollBar = (ScrollBar)numericUpDown.Tag;
            scrollBar.Value = (int)numericUpDown.Value;*/
        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            //numericUpDown1.Value = (int)hScrollBar1.Value;
            hScrollBar1.Value = (int)numericUpDown1.Value;
            UpdateColor();
           /* ScrollBar scrollBar = (ScrollBar)sender;
            NumericUpDown numericUpDown = (NumericUpDown)scrollBar.Tag;
            numericUpDown.Value = scrollBar.Value;*/
        }

        private void hScrollBar2_ValueChanged(object sender, EventArgs e)
        {
            numericUpDown2.Value = (int)hScrollBar2.Value;
        }

        private void hScrollBar3_ValueChanged(object sender, EventArgs e)
        {
            numericUpDown3.Value = (int)hScrollBar3.Value;
        }

        private void numericUpDown2_ValueChanged(object sender, EventArgs e)
        {
            hScrollBar2.Value = (int)numericUpDown2.Value;
            UpdateColor();
        }

        private void numericUpDown3_ValueChanged(object sender, EventArgs e)
        {
            hScrollBar3.Value = (int)numericUpDown3.Value;
            UpdateColor();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            hScrollBar1.Value = 0;
            hScrollBar2.Value = 0;
            hScrollBar3.Value = 0;

            numericUpDown1.Value = 0;
            numericUpDown2.Value = 0;
            numericUpDown3.Value = 0;
        }
    }
}
