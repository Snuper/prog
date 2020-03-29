using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form2 : Form
    {

        public Form2()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        public int Section = 1;
        public string UserInput = " ";

        public void btnAddNew_Click(object sender, EventArgs e)
        {
            Form1 main = this.Owner as Form1;
            if (main != null)

            UserInput = Word.Text;

            if (radioButton1.Checked)
            {
                main.lstSection1.Items.Add(UserInput);
            }

            if (radioButton2.Checked)
            {
                main.lstSection2.Items.Add(UserInput);
            }
            this.Close();
        }

    }
}
