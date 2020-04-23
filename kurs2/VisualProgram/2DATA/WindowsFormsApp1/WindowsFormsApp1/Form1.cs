using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: данная строка кода позволяет загрузить данные в таблицу "lab2DataSet.Страныдля2лабы". При необходимости она может быть перемещена или удалена.
            this.страныдля2лабыTableAdapter.Fill(this.lab2DataSet.Страныдля2лабы);

        }

        private void button7_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Якунин Андрей и Парфенцов Семен ИП-814");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            try
            {
                this.страныдля2лабыTableAdapter.FillBy3(this.lab2DataSet.Страныдля2лабы);
             }
            catch (System.Exception ex)
            {
                System.Windows.Forms.MessageBox.Show(ex.Message);
            }
}

        private void button5_Click(object sender, EventArgs e)
        {
            try
            {
                this.страныдля2лабыTableAdapter.FillBy2(this.lab2DataSet.Страныдля2лабы);
            }
            catch (System.Exception ex)
            {
                System.Windows.Forms.MessageBox.Show(ex.Message);
            }

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            for (int i = 0; i < dataGridView1.RowCount - 1; i++)

            {

                string str = dataGridView1.Rows[i].Cells[2].Value.ToString();

                if (str.Contains(textBox1.Text) == true) dataGridView1.Rows[i].Selected = true;

                else dataGridView1.Rows[i].Selected = false;

                if (textBox1.Text == "") dataGridView1.Rows[i].Selected = false;

            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.страныдля2лабыTableAdapter.Fill(this.lab2DataSet.Страныдля2лабы);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                this.страныдля2лабыTableAdapter.FillBy6(this.lab2DataSet.Страныдля2лабы);
            }
            catch (System.Exception ex)
            {
                System.Windows.Forms.MessageBox.Show(ex.Message);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            try
            {
                this.страныдля2лабыTableAdapter.FillBy5(this.lab2DataSet.Страныдля2лабы);
            }
            catch (System.Exception ex)
            {
                System.Windows.Forms.MessageBox.Show(ex.Message);
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            try
            {
                this.страныдля2лабыTableAdapter.FillBy4(this.lab2DataSet.Страныдля2лабы);
            }
            catch (System.Exception ex)
            {
                System.Windows.Forms.MessageBox.Show(ex.Message);
            }
        }
    }
}
