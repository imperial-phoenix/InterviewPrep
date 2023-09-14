#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

class Matrix
{
public:

   Matrix(int num_rows = 0, int num_columns = 0)
   {
      // if (num_rows != 0)
      // {
         data_.resize(num_rows);
         for (size_t i = 0; i < num_rows; ++i)
         {
            data_[i].resize(num_columns);
         }
      // }
   }


   int& At(size_t row, size_t column)
   {
      return data_[row][column];
   }


   int At(size_t row, size_t column) const
   {
      return data_[row][column];
   }



   int GetNumRows() const
   {
      return data_.size();
   }


   int GetNumColumns() const
   {
      if (!data_.empty())
      {
         return data_[0].size();
      }

      return 0;
   }

private:
   std::vector<std::vector<int>> data_;
};


std::istream& operator>>(std::istream& in, Matrix& matrix)
{
   int num_rows;
   int num_columns;

   in >> num_rows >> num_columns;

   Matrix new_matrix(num_rows, num_columns);
   
   for (int i = 0; i < num_rows; ++i)
   {
      for (int j = 0; j < num_columns; ++j)
      {
         in >> new_matrix.At(i, j);
      }
   }

   matrix = new_matrix;

   return in;
}


std::ostream& operator<<(std::ostream& out, const Matrix& matrix)
{
   out << matrix.GetNumRows() << " " << matrix.GetNumColumns() << std::endl;

   for (int i = 0; i < matrix.GetNumRows(); ++i)
   {
      for (int j = 0; j < matrix.GetNumColumns(); ++j)
      {
         out << matrix.At(i, j) << " ";
      }
      std::cout << std::endl;
   }

   return out;
}


int main()
{
   // Matrix a(2, 3);
   Matrix a;
   std::cin >> a;
   std::cout << a << std::endl;


//   Matrix one;
//   Matrix two;

//   cin >> one >> two;
//   cout << one + two << endl;
  return 0;
}
