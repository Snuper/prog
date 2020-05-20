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
        string temp_text1, temp_text2, temp_text3;
        string temp1;
        string temp2;
        string save_data;

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
            // TODO: данная строка кода позволяет загрузить данные в таблицу "mainDataSet.Автошкола". При необходимости она может быть перемещена или удалена.
            this.автошколаTableAdapter.Fill(this.mainDataSet.Автошкола);
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
            string str;
            string temp;
            int indexOfChar = -1;

           

            for (int i = 0; i < dataGridView2.RowCount - 1; i++)
            {
                str = dataGridView2.Rows[i].Cells[1].Value.ToString();
                temp = textBox1.Text;

                
                    indexOfChar = str.IndexOf(temp);
                    if (indexOfChar >= 0)
                    {
                        dataGridView2.Rows[i].Selected = true;
                        indexOfChar = -1;
                     
                    }

                    else dataGridView2.Rows[i].Selected = false;
                
            }

            if (textBox1.Text == "") for (int i = 0; i < dataGridView2.RowCount - 1; i++) dataGridView2.Rows[i].Selected = false;
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            string str;
            string temp;
            int indexOfChar = -1;



            for (int i = 0; i < dataGridView2.RowCount - 1; i++)
            {
                str = dataGridView2.Rows[i].Cells[9].Value.ToString();
                temp = textBox2.Text;


                indexOfChar = str.IndexOf(temp);
                if (indexOfChar >= 0)
                {
                    dataGridView2.Rows[i].Selected = true;
                    indexOfChar = -1;

                }

                else dataGridView2.Rows[i].Selected = false;

            }

            if (textBox2.Text == "") for (int i = 0; i < dataGridView2.RowCount - 1; i++) dataGridView2.Rows[i].Selected = false;
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            string str;
            string temp;
            int indexOfChar = -1;



            for (int i = 0; i < dataGridView2.RowCount - 1; i++)
            {
                str = dataGridView2.Rows[i].Cells[12].Value.ToString();
                temp = textBox3.Text;


                indexOfChar = str.IndexOf(temp);
                if (indexOfChar >= 0)
                {
                    dataGridView2.Rows[i].Selected = true;
                    indexOfChar = -1;

                }

                else dataGridView2.Rows[i].Selected = false;

            }

            if (textBox3.Text == "") for (int i = 0; i < dataGridView2.RowCount - 1; i++) dataGridView2.Rows[i].Selected = false;
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
            MessageBox.Show("Автошкола Зайцева\nДиректор - Ерохи Олег Петрович\nРеквизиты - 182 1 06 04011 02 1000 110\nНачальник отдела ГИБДД - Песков Юрий Андреевич");
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
            MessageBox.Show("Автошкола Зайцева\nДиректор - Ерохин Олег Петрович\nАдрес - Ленина 1\nРеквизиты - 182 1 06 04011 02 1000 110\nНачальник отдела ГИБДД - Песков Юрий Андреевич");
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
            
                PrintDocument printDocument = new PrintDocument();

                // обработчик события печати
                printDocument.PrintPage += PrintPageHandler1;

                // диалог настройки печати
                PrintDialog printDialog = new PrintDialog();

                // установка объекта печати для его настройки
                printDialog.Document = printDocument;

                // если в диалоге было нажато ОК
                if (printDialog.ShowDialog() == DialogResult.OK)
                    printDialog.Document.Print(); // печатаем
           
        }

        private void PrintPageHandler1(object sender, PrintPageEventArgs e)
        {
            e.Graphics.FillRectangle(Brushes.White, 100, 50, 550, 300);
            e.Graphics.DrawRectangle(Pens.Black, 100, 50, 550, 300);
            for (int i = 0; i < dataGridView2.RowCount - 1; i++)
            {
                if (dataGridView2.Rows[i].Cells[3].Value.ToString() == textBox3.Text)
                {
                    save_data = dataGridView2.Rows[i].Cells[1].Value.ToString();
                    break;
                }
            }
            for (int i = 0; i < dataGridView2.Rows.Count - 1; i++)
            {
                if (dataGridView2.Rows[i].Selected == true)
                {
                    e.Graphics.DrawString("Директору автошколы " + dataGridView3.Rows[0].Cells[3].Value.ToString() + " " + dataGridView3.Rows[0].Cells[2].Value.ToString(), dataGridView3.Font, Brushes.Black, 200, 60);
                  
                    e.Graphics.DrawString("Я" + " " + dataGridView2.Rows[i].Cells[1].Value.ToString(), dataGridView2.Font, Brushes.Black, 300, 190);
                    e.Graphics.DrawString("Прошу принять меня на обучение в автошколу", dataGridView2.Font, Brushes.Black, 250, 210);
                    
                    e.Graphics.DrawString(save_data, dataGridView2.Font, Brushes.Black, 250, 210);
     
                    e.Graphics.DrawString("Подпись____________", dataGridView2.Font, Brushes.Black, 485, 270);
                    e.Graphics.DrawString("Дата: " + DateTime.Now, dataGridView2.Font, Brushes.Black, 485, 290);

                }
            }
        }


        private void printPreviewDialog2_Load(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            for (int i = 0; i < dataGridView2.RowCount - 1; i++)
            {
                string str = dataGridView2.Rows[i].Cells[0].Value.ToString();
                if (str == textBox4.Text) dataGridView2.Rows[i].Selected = true;
                else dataGridView2.Rows[i].Selected = false;
            }

        }

        private void PrintPageHandler2(object sender, PrintPageEventArgs e)
        {
            e.Graphics.FillRectangle(Brushes.White, 100, 50, 550, 300);
            e.Graphics.DrawRectangle(Pens.Black, 100, 50, 550, 300);
            
            for (int i = 0; i < dataGridView2.Rows.Count - 1; i++)
            {
                if (dataGridView2.Rows[i].Selected == true)
                {
                    e.Graphics.DrawString(dataGridView3.Rows[0].Cells[3].Value.ToString(), dataGridView3.Font, Brushes.Black, 470, 60);
                    e.Graphics.DrawString(dataGridView3.Rows[0].Cells[1].Value.ToString(), dataGridView3.Font, Brushes.Black, 470, 80);
                    e.Graphics.DrawString("Директор " + dataGridView3.Rows[0].Cells[0].Value.ToString(), dataGridView3.Font, Brushes.Black, 470, 100);

                    e.Graphics.DrawString("Заявки на регистрацию учебных групп", dataGridView3.Font, Brushes.Black, 270, 150);
                    e.Graphics.DrawString(save_data, dataGridView3.Font, Brushes.Black, 250, 210);

                    e.Graphics.DrawString("Подпись____________", dataGridView2.Font, Brushes.Black, 485, 270);
                    e.Graphics.DrawString("Дата: " + DateTime.Now, dataGridView2.Font, Brushes.Black, 485, 290);

                }
            }
        }

        private void печатьЗаявкиНаРегистрациюУчебныхГруппToolStripMenuItem_Click(object sender, EventArgs e)
        {
          
          
                PrintDocument printDocument = new PrintDocument();

                // обработчик события печати
                printDocument.PrintPage += PrintPageHandler2;

                // диалог настройки печати
                PrintDialog printDialog = new PrintDialog();

                // установка объекта печати для его настройки
                printDialog.Document = printDocument;

                // если в диалоге было нажато ОК
                if (printDialog.ShowDialog() == DialogResult.OK)
                    printDialog.Document.Print(); // печатаем
           
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            temp1 = textBox5.Text;
        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {
            temp2 = textBox6.Text;
        }

        private void PrintPageHandler3(object sender, PrintPageEventArgs e)
        {
            e.Graphics.FillRectangle(Brushes.White, 100, 50, 550, 300);
            e.Graphics.DrawRectangle(Pens.Black, 100, 50, 550, 300);
           
            for (int i = 0; i < dataGridView2.Rows.Count - 1; i++)
            {
                if (dataGridView2.Rows[i].Selected == true)
                {
                    e.Graphics.DrawString(dataGridView3.Rows[0].Cells[3].Value.ToString(), dataGridView3.Font, Brushes.Black, 470, 60);
                    e.Graphics.DrawString(dataGridView3.Rows[0].Cells[1].Value.ToString(), dataGridView3.Font, Brushes.Black, 470, 80);
                    e.Graphics.DrawString("Директор " + dataGridView3.Rows[0].Cells[0].Value.ToString(), dataGridView3.Font, Brushes.Black, 470, 100);

                    e.Graphics.DrawString("Приказ о зачислении учащихся", dataGridView3.Font, Brushes.Black, 300, 120);
                    e.Graphics.DrawString("Список групп", dataGridView3.Font, Brushes.Black, 350, 140);
                    e.Graphics.DrawString("Группа " + dataGridView1.Rows[0].Cells[1].Value.ToString() + " Преподователь " + dataGridView1.Rows[0].Cells[4].Value.ToString() + " Гос номер " + dataGridView1.Rows[0].Cells[5].Value.ToString() + " Марка " + dataGridView1.Rows[0].Cells[6].Value.ToString(), dataGridView3.Font, Brushes.Black, 120, 170);
                    e.Graphics.DrawString("Группа " + dataGridView1.Rows[1].Cells[1].Value.ToString() + " Преподователь " + dataGridView1.Rows[1].Cells[4].Value.ToString() + " Гос номер " + dataGridView1.Rows[1].Cells[5].Value.ToString() + " Марка " + dataGridView1.Rows[1].Cells[6].Value.ToString(), dataGridView3.Font, Brushes.Black, 120, 190);
                    e.Graphics.DrawString("Группа " + dataGridView1.Rows[2].Cells[1].Value.ToString() + " Преподователь " + dataGridView1.Rows[2].Cells[4].Value.ToString() + " Гос номер " + dataGridView1.Rows[2].Cells[5].Value.ToString() + " Марка " + dataGridView1.Rows[2].Cells[6].Value.ToString(), dataGridView3.Font, Brushes.Black, 120, 210);
                    e.Graphics.DrawString("Группа " + dataGridView1.Rows[3].Cells[1].Value.ToString() + " Преподователь " + dataGridView1.Rows[3].Cells[4].Value.ToString() + " Гос номер " + dataGridView1.Rows[3].Cells[5].Value.ToString() + " Марка " + dataGridView1.Rows[3].Cells[6].Value.ToString(), dataGridView3.Font, Brushes.Black, 120, 230);
                    e.Graphics.DrawString("Группа " + dataGridView1.Rows[4].Cells[1].Value.ToString() + " Преподователь " + dataGridView1.Rows[4].Cells[4].Value.ToString() + " Гос номер " + dataGridView1.Rows[4].Cells[5].Value.ToString() + " Марка " + dataGridView1.Rows[4].Cells[6].Value.ToString(), dataGridView3.Font, Brushes.Black, 120, 250);
                    e.Graphics.DrawString(save_data, dataGridView3.Font, Brushes.Black, 250, 210);

                    e.Graphics.DrawString("Подпись____________", dataGridView2.Font, Brushes.Black, 485, 270);
                    e.Graphics.DrawString("Дата: " + temp2, dataGridView2.Font, Brushes.Black, 485, 290);
                    e.Graphics.DrawString("Номер приказа: " + temp1, dataGridView2.Font, Brushes.Black, 485, 310);
                }
            }
        }

        private void печатьПриказаОЗачисленииУчащихсяToolStripMenuItem_Click(object sender, EventArgs e)
        {
           
                PrintDocument printDocument = new PrintDocument();

                // обработчик события печати
                printDocument.PrintPage += PrintPageHandler3;

                // диалог настройки печати
                PrintDialog printDialog = new PrintDialog();

                // установка объекта печати для его настройки
                printDialog.Document = printDocument;

                // если в диалоге было нажато ОК
                if (printDialog.ShowDialog() == DialogResult.OK)
                    printDialog.Document.Print(); // печатаем
           
        }

        private void PrintPageHandler4(object sender, PrintPageEventArgs e)
        {
            e.Graphics.FillRectangle(Brushes.White, 100, 50, 550, 300);
            e.Graphics.DrawRectangle(Pens.Black, 100, 50, 550, 300);
            for (int i = 0; i < dataGridView2.RowCount - 1; i++)
            {
                if (dataGridView2.Rows[i].Cells[3].Value.ToString() == textBox3.Text)
                {
                    save_data = dataGridView2.Rows[i].Cells[1].Value.ToString();
                    break;
                }
            }
            for (int i = 0; i < dataGridView2.Rows.Count - 1; i++)
            {
                if (dataGridView2.Rows[i].Selected == true)
                {
                    
                    e.Graphics.DrawString("Карточка вождения", dataGridView2.Font, Brushes.Black, 320, 60);
                  
                    e.Graphics.DrawString(dataGridView3.Rows[0].Cells[3].Value.ToString(), dataGridView2.Font, Brushes.Black, 300, 100);
                   
                    e.Graphics.DrawString("ФИО - " + dataGridView2.Rows[i].Cells[1].Value.ToString(), dataGridView2.Font, Brushes.Black, 300, 120);
                    e.Graphics.DrawString("Адрес - " + dataGridView2.Rows[i].Cells[5].Value.ToString(), dataGridView2.Font, Brushes.Black, 300, 140);
                    e.Graphics.DrawString("Место работы - " + dataGridView2.Rows[i].Cells[4].Value.ToString(), dataGridView2.Font, Brushes.Black, 300, 160);
                    e.Graphics.DrawString("Категория - В", dataGridView2.Font, Brushes.Black, 300, 180);

                }
            }
        }

        private void печатьКарточкиВожденияToolStripMenuItem_Click(object sender, EventArgs e)
        {
            
                PrintDocument printDocument = new PrintDocument();

                // обработчик события печати
                printDocument.PrintPage += PrintPageHandler4;

                // диалог настройки печати
                PrintDialog printDialog = new PrintDialog();

                // установка объекта печати для его настройки
                printDialog.Document = printDocument;

                // если в диалоге было нажато ОК
                if (printDialog.ShowDialog() == DialogResult.OK)
                    printDialog.Document.Print(); // печатаем
          
        }

        private void PrintPageHandler5(object sender, PrintPageEventArgs e)
        {
            e.Graphics.FillRectangle(Brushes.White, 100, 50, 550, 300);
            e.Graphics.DrawRectangle(Pens.Black, 100, 50, 550, 300);
            for (int i = 0; i < dataGridView2.RowCount - 1; i++)
            {
                if (dataGridView2.Rows[i].Cells[3].Value.ToString() == textBox3.Text)
                {
                    save_data = dataGridView2.Rows[i].Cells[1].Value.ToString();
                    break;
                }
            }
            for (int i = 0; i < dataGridView2.Rows.Count - 1; i++)
            {
                if (dataGridView2.Rows[i].Selected == true)
                {

                    e.Graphics.DrawString("Квитанция", dataGridView2.Font, Brushes.Black, 340, 60);


                    
                    e.Graphics.DrawString("ФИО - " + dataGridView2.Rows[i].Cells[1].Value.ToString(), dataGridView2.Font, Brushes.Black, 250, 190);
                    e.Graphics.DrawString("Адрес - " + dataGridView2.Rows[i].Cells[5].Value.ToString(), dataGridView2.Font, Brushes.Black, 250, 210);
                    e.Graphics.DrawString("Сумма - ", dataGridView2.Font, Brushes.Black, 250, 230);

                }
            }
        }

        private void печатьПлатежногоПорученияЗаСдачуЭкзаменаВГИБДДИзвещениеИКвитанцияToolStripMenuItem_Click(object sender, EventArgs e)
        {
            PrintDocument printDocument = new PrintDocument();

            // обработчик события печати
            printDocument.PrintPage += PrintPageHandler5;

            // диалог настройки печати
            PrintDialog printDialog = new PrintDialog();

            // установка объекта печати для его настройки
            printDialog.Document = printDocument;

            // если в диалоге было нажато ОК
            if (printDialog.ShowDialog() == DialogResult.OK)
                printDialog.Document.Print(); // печатаем
        }

        private void PrintPageHandler6(object sender, PrintPageEventArgs e)
        {
            e.Graphics.FillRectangle(Brushes.White, 100, 50, 550, 300);
            e.Graphics.DrawRectangle(Pens.Black, 100, 50, 550, 300);
            for (int i = 0; i < dataGridView2.RowCount - 1; i++)
            {
                if (dataGridView2.Rows[i].Cells[3].Value.ToString() == textBox3.Text)
                {
                    save_data = dataGridView2.Rows[i].Cells[1].Value.ToString();
                    break;
                }
            }
            for (int i = 0; i < dataGridView2.Rows.Count - 1; i++)
            {
                if (dataGridView2.Rows[i].Selected == true)
                {

                    e.Graphics.DrawString("Экзаменационная карточка по ПДД ", dataGridView2.Font, Brushes.Black, 280, 60);



                    e.Graphics.DrawString("ФИО - " + dataGridView2.Rows[i].Cells[1].Value.ToString(), dataGridView2.Font, Brushes.Black, 230, 190);
                    e.Graphics.DrawString("Дата сдачи - " + dataGridView2.Rows[i].Cells[10].Value.ToString(), dataGridView2.Font, Brushes.Black, 280, 210);
                    e.Graphics.DrawString("Категория - B ", dataGridView2.Font, Brushes.Black, 280, 230);

                }
            }
        }

        private void печатьЭкзаменационнойКарточкиПоПДДToolStripMenuItem_Click(object sender, EventArgs e)
        {
            PrintDocument printDocument = new PrintDocument();

            // обработчик события печати
            printDocument.PrintPage += PrintPageHandler6;

            // диалог настройки печати
            PrintDialog printDialog = new PrintDialog();

            // установка объекта печати для его настройки
            printDialog.Document = printDocument;

            // если в диалоге было нажато ОК
            if (printDialog.ShowDialog() == DialogResult.OK)
                printDialog.Document.Print(); // печатаем
        }

        private void PrintPageHandler7(object sender, PrintPageEventArgs e)
        {
            e.Graphics.FillRectangle(Brushes.White, 100, 50, 550, 300);
            e.Graphics.DrawRectangle(Pens.Black, 100, 50, 550, 300);
            for (int i = 0; i < dataGridView2.RowCount - 1; i++)
            {
                if (dataGridView2.Rows[i].Cells[3].Value.ToString() == textBox3.Text)
                {
                    save_data = dataGridView2.Rows[i].Cells[1].Value.ToString();
                    break;
                }
            }
            for (int i = 0; i < dataGridView2.Rows.Count - 1; i++)
            {
                if (dataGridView2.Rows[i].Selected == true)
                {

                    e.Graphics.DrawString("Экзаменационной лист", dataGridView2.Font, Brushes.Black, 300, 60);



                    e.Graphics.DrawString("ФИО - " + dataGridView2.Rows[i].Cells[1].Value.ToString(), dataGridView2.Font, Brushes.Black, 230, 120);
                    e.Graphics.DrawString("Дата сдачи - " + dataGridView2.Rows[i].Cells[10].Value.ToString(), dataGridView2.Font, Brushes.Black, 280, 140);
                    e.Graphics.DrawString("Категория - B ", dataGridView2.Font, Brushes.Black, 280, 160);

                    e.Graphics.DrawString("1)            " + "2)            " + "3)            ", dataGridView2.Font, Brushes.Black, 280, 180);
                    e.Graphics.DrawString("4)            " + "5)            " + "6)            ", dataGridView2.Font, Brushes.Black, 280, 200);
                    e.Graphics.DrawString("7)            " + "8)            " + "9)            ", dataGridView2.Font, Brushes.Black, 280, 220);

                }
            }
        }

        private void печатьЭкзаменационногоЛистаToolStripMenuItem_Click(object sender, EventArgs e)
        {
            PrintDocument printDocument = new PrintDocument();

            // обработчик события печати
            printDocument.PrintPage += PrintPageHandler7;

            // диалог настройки печати
            PrintDialog printDialog = new PrintDialog();

            // установка объекта печати для его настройки
            printDialog.Document = printDocument;

            // если в диалоге было нажато ОК
            if (printDialog.ShowDialog() == DialogResult.OK)
                printDialog.Document.Print(); // печатаем
        }

        private void PrintPageHandler8(object sender, PrintPageEventArgs e)
        {
            e.Graphics.FillRectangle(Brushes.White, 100, 50, 550, 300);
            e.Graphics.DrawRectangle(Pens.Black, 100, 50, 550, 300);
            for (int i = 0; i < dataGridView2.RowCount - 1; i++)
            {
                if (dataGridView2.Rows[i].Cells[3].Value.ToString() == textBox3.Text)
                {
                    save_data = dataGridView2.Rows[i].Cells[1].Value.ToString();
                    break;
                }
            }
            for (int i = 0; i < dataGridView2.Rows.Count - 1; i++)
            {
                if (dataGridView2.Rows[i].Selected == true)
                {

                    e.Graphics.DrawString("Карточка", dataGridView2.Font, Brushes.Black, 350, 60);

                    e.Graphics.DrawString("ФИО - " + dataGridView2.Rows[i].Cells[1].Value.ToString(), dataGridView2.Font, Brushes.Black, 230, 180);
                    e.Graphics.DrawString("Дата сдачи - " + dataGridView2.Rows[i].Cells[10].Value.ToString(), dataGridView2.Font, Brushes.Black, 280, 200);
                    e.Graphics.DrawString("Категория - B ", dataGridView2.Font, Brushes.Black, 280, 220);
                    e.Graphics.DrawString("Результат - Сдал", dataGridView2.Font, Brushes.Black, 360, 240);





                }
            }
        }

        private void печатьКарточкиToolStripMenuItem_Click(object sender, EventArgs e)
        {
            PrintDocument printDocument = new PrintDocument();

            // обработчик события печати
            printDocument.PrintPage += PrintPageHandler8;

            // диалог настройки печати
            PrintDialog printDialog = new PrintDialog();

            // установка объекта печати для его настройки
            printDialog.Document = printDocument;

            // если в диалоге было нажато ОК
            if (printDialog.ShowDialog() == DialogResult.OK)
                printDialog.Document.Print(); // печатаем
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            try
            {
                this.группаTableAdapter.FillBy(this.dATAS.Группа);
            }
            catch (System.Exception ex)
            {
                System.Windows.Forms.MessageBox.Show(ex.Message);
            }
        }
    }
}
