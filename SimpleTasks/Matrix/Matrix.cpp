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
      if (num_columns == 0 || num_rows == 0)
      {
         return;
      }

      data_.resize(num_rows);
      for (size_t i = 0; i < num_rows; ++i)
      {
         data_[i].resize(num_columns);
      }
   }


   void Reset(int num_rows, int num_columns)
   {
      if (num_rows < 0 || num_columns < 0)
      {
         throw std::out_of_range("");
      }

      data_.clear();

      data_.resize(num_rows);
      for (size_t i = 0; i < num_rows; ++i)
      {
         data_[i].resize(num_columns);
      }
   }


   int& At(size_t row, size_t column)
   {
      if (row >= this->GetNumRows() || column >= this->GetNumColumns())
      {
         throw std::out_of_range("");
      }

      return data_[row][column];
   }


   int At(size_t row, size_t column) const
   {
      if (row >= this->GetNumRows() || column >= this->GetNumColumns())
      {
         throw std::out_of_range("");
      }

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
      if (i != matrix.GetNumRows() - 1)
      {
         out << std::endl;
      }
   }

   return out;
}


bool operator==(const Matrix& lhs, const Matrix& rhs)
{
   if ((lhs.GetNumRows() != rhs.GetNumRows()) || (lhs.GetNumColumns() != rhs.GetNumColumns()))
   {
      return false;
   }

   for (size_t i = 0; i < lhs.GetNumRows(); ++i)
   {
      for (size_t j = 0; j < lhs.GetNumColumns(); ++j)
      {
         if (lhs.At(i,j) != rhs.At(i,j))
         {
            return false;
         }
      }
   }

   return true;
}


Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
   if ((lhs.GetNumRows() != rhs.GetNumRows()) || (lhs.GetNumColumns() != rhs.GetNumColumns()))
   {
      throw std::invalid_argument("");
   }

   Matrix matrix(lhs.GetNumRows(), lhs.GetNumColumns());
   for (size_t i = 0; i < lhs.GetNumRows(); ++i)
   {
      for (size_t j = 0; j < rhs.GetNumColumns(); ++j)
      {
         matrix.At(i,j) = lhs.At(i,j) + rhs.At(i,j);
      }
   }

   return matrix;
}


int main()
{
   Matrix a;
   std::cin >> a;
   std::cout << "--------------------------------------------------\n";
   std::cout << a << std::endl;

   // Matrix one(2,2);
   // Matrix two(2,1);

   // try
   // {
   //    std::cout << one.At(2,2) << std::endl;
   // }
   // catch (std::exception& ex)
   // {
   //    std::cout << ex.what() << std::endl;
   // }

   return 0;
}
