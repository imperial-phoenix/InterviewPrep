#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;


class Matrix
{
public:

   Matrix(int num_rows = 0, int num_columns = 0)
   {
      Reset(num_rows, num_columns);
   }


   void Reset(int num_rows, int num_columns)
   {
      if (num_rows < 0)
      {
         throw std::out_of_range("num_rows must be > 0");
      }
      if (num_columns < 0)
      {
         throw std::out_of_range("num_columns must be > 0");
      }
      if (num_columns == 0 || num_rows == 0)
      {
         num_columns = num_rows = 0;
      }

      data_.assign(num_rows, std::vector<int>(num_columns));
   }


   int& At(size_t row, size_t column)
   {
      return data_.at(row).at(column);
   }


   int At(size_t row, size_t column) const
   {
      return data_.at(row).at(column);
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

   matrix.Reset(num_rows, num_columns);

   for (int i = 0; i < num_rows; ++i)
   {
      for (int j = 0; j < num_columns; ++j)
      {
         in >> matrix.At(i, j);
      }
   }

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
   if (lhs.GetNumRows() != rhs.GetNumRows())
   {
      throw invalid_argument("Mismatched number of rows");
   }
   if (lhs.GetNumColumns() != rhs.GetNumColumns())
   {
      throw invalid_argument("Mismatched number of columns");
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


   return 0;
}
