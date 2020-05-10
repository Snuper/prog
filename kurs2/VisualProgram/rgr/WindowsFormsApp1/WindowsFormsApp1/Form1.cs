using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Drawing.Printing;


namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        // Declare a string to hold the entire document contents.
        private string documentContents;

        // Declare a variable to hold the portion of the document that
        // is not printed.
        private string stringToPrint;

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: данная строка кода позволяет загрузить данные в таблицу "dATAS.Курсант". При необходимости она может быть перемещена или удалена.
            this.курсантTableAdapter.Fill(this.dATAS.Курсант);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "dATAS.Группа". При необходимости она может быть перемещена или удалена.
            this.группаTableAdapter.Fill(this.dATAS.Группа);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Якунин Андрей ИП-814");
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            for (int i = 0; i < dataGridView2.RowCount - 1; i++)
            {
                string str = dataGridView2.Rows[i].Cells[1].Value.ToString();
                if (str == textBox1.Text) dataGridView2.Rows[i].Selected = true;
                else dataGridView2.Rows[i].Selected = false;
            }
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            for (int i = 0; i < dataGridView2.RowCount - 1; i++)
            {
                string str = dataGridView2.Rows[i].Cells[9].Value.ToString();
                if (str == textBox2.Text) dataGridView2.Rows[i].Selected = true;
                else dataGridView2.Rows[i].Selected = false;
            }
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            for (int i = 0; i < dataGridView2.RowCount - 1; i++)
            {
                string str = dataGridView2.Rows[i].Cells[12].Value.ToString();
                if (str == textBox3.Text) dataGridView2.Rows[i].Selected = true;
                else dataGridView2.Rows[i].Selected = false;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                this.группаTableAdapter.FillBy12(this.dATAS.Группа);
            }
            catch (System.Exception ex)
            {
                System.Windows.Forms.MessageBox.Show(ex.Message);
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            try
            {
                this.группаTableAdapter.FillBy1(this.dATAS.Группа);
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
                this.группаTableAdapter.FillBy13(this.dATAS.Группа);
            }
            catch (System.Exception ex)
            {
                System.Windows.Forms.MessageBox.Show(ex.Message);
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Автошкола Зайцева\nДиректор - Ерохин Олег Петрович\nРеквизиты - 182 1 06 04011 02 1000 110\nНачальник отдела ГИБДД - Песков Юрий Андреевич");
        }

        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void bindingNavigator1_RefreshItems(object sender, EventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void bindingNavigator2_RefreshItems(object sender, EventArgs e)
        {

        }

        private void toolStripLabel1_Click(object sender, EventArgs e)
        {

        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Якунин Андрей ИП-814");
        }

        private void автошколаToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Автошкола Зайцева\nДиректор - Ерохин Олег Петрович\nРеквизиты - 182 1 06 04011 02 1000 110\nНачальник отдела ГИБДД - Песков Юрий Андреевич");
        }

        private void ReadDocument()
        {
            string docName = "direcotr_name.txt";
            printDocument2.DocumentName = docName;
            using (FileStream stream = new FileStream(docName, FileMode.Open))
            using (StreamReader reader = new StreamReader(stream))
            {
                documentContents = reader.ReadToEnd();
            }
            stringToPrint = documentContents;
        }

        private void printDocument2_PrintPage(object sender, PrintPageEventArgs e)
        {
            int charactersOnPage = 0;
            int linesPerPage = 0;


            e.Graphics.MeasureString(stringToPrint, this.Font,
                e.MarginBounds.Size, StringFormat.GenericTypographic,
                out charactersOnPage, out linesPerPage);


            e.Graphics.DrawString(stringToPrint, this.Font, Brushes.Black,
            e.MarginBounds, StringFormat.GenericTypographic);


            stringToPrint = stringToPrint.Substring(charactersOnPage);


            e.HasMorePages = (stringToPrint.Length > 0);


            if (!e.HasMorePages)
                stringToPrint = documentContents;
        }

    
        private void печатьToolStripMenuItem_Click_1(object sender, EventArgs e)
        {

        }

        private void печатьЗаявленияНаИмяДиректораАвтошколыНаПринятиеКурсантаToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ReadDocument();
            printPreviewDialog2.Document = printDocument2;
            printPreviewDialog2.ShowDialog();
        }


        private void printPreviewDialog2_Load(object sender, EventArgs e)
        {

        }
    }
}
