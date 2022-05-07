/*
 * Copyright 2022, Hutton Grabiel
 */

#pragma once

#include <Vector.h>

namespace DTS {

template<typename T>
class Set {
public:

   [[nodiscard]] bool is_empty() { return size() == 0; }

   [[nodiscard]] size_t size() { return set.size(); }

   [[nodiscard]] size_t max_size() { return set.max_size(); }

   size_t count(T value)
   {
        size_t count = 0;
        size_t set_size = set.size();
        for (size_t i = 0; i < set_size; i++)
            if (set[i] == value)
                count++;

        return count;
   }

   void insert(const T& value)
   {
       if (count(value))
           return;

       size_t set_size = set.size();
       size_t insert_position = 0;

       if (set_size == 0) {
           set.push_back(value);
       }
       else if (set_size == 1) {
           insert_position = value > set[0] ? 1 : 0;
           set.insert(value, insert_position);
       }
       else {
           for (size_t i = 0; i < set_size; i++) {

               if (value > set[i] && value < set[i + 1]) {
                   insert_position = i + 1;
                   break;
               }
           }

           set.insert(value, insert_position);
       }
   }

   void insert(T&& value)
   {
       if (count(value))
           return;

       size_t set_size = set.size();
       size_t insert_position = 0;

       if (set_size == 0 || value > set[set_size-1]) {
           set.push_back(value);
       }
       else if (set_size == 1) {
           insert_position = value > set[0] ? 1 : 0;
           set.insert(value, insert_position);
       }
       else {
           for (size_t i = 0; i < set_size; i++) {
               if (value > set[i] && value < set[i + 1]) {
                   insert_position = i + 1;
                   break;
               }
           }

           set.insert(value, insert_position);
       }
   }

   bool contains(T&& value)
   {
        if (count(value) > 0)
            return true;
        return false;
   }

   bool contains(const T& value)
   {
       if (count(value) > 0)
           return true;
       return false;
   }

   // FIXME: Should return an iterator to the element. Fix once iterator is implemented
   bool find(T&& value)
   {
        return count(value);
   }

   // FIXME: Should return an iterator to the element. Fix once iterator is implemented
   bool find(const T& value)
   {
       return count(value);
   }

   void erase(T&& value)
   {
       size_t set_size = set.size();
       size_t erase_index = 0;
       for (size_t i = 0; i < set_size; i++)
           if (set[i] == value)
               erase_index = i;

       set.erase(erase_index);
   }

   void erase(const T& value)
   {
       size_t set_size = set.size();
       size_t erase_index = 0;
       for (size_t i = 0; i < set_size; i++)
           if (set[i] == value)
               erase_index = i;

       set.erase(erase_index);
   }

   void clear()
   {
       set.clear();
   }

   T* data()
   {
       return set.data();
   }

   T* data() const
   {
       return set.data();
   }

   T operator[](size_t index)
   {
        return set[index];
   }

private:
    Vector<T> set;
};

}