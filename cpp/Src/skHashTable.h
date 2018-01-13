/*
  Copyright 1996-2001
  Simon Whiteside

  $Id: skHashTable.h,v 1.12 2001/03/05 16:46:28 sdw Exp $
*/
#ifndef skHASHTBL_H
#define skHASHTBL_H


#include "skGeneral.h"
#include "skAlist.h"

/**
 * this class represents a single entry in the hashtable
 */
class  skHashEntry 
{    
 public:
  /**
   * Constructor
   */
  skHashEntry(void * k,void * v) 
    : m_Key(k), m_Value(v) {
  }
  /**
   * Equality comparison - tests pointer equivalence
   */
  int	operator==(const skHashEntry& h) { 
    return this==&h; 
  }
  void * m_Key;
  void * m_Value;
};

typedef skTAList<skHashEntry> skHashEntryList;
typedef skTAListIterator<skHashEntry> skHashEntryListIterator;

/**
   HashTable Class with template sub-class for type-safety
*/

class   skHashTable 
{
 public:
  /**
   * this clears the entries from the table, but does *not* delete them
   */
  void clear();
  /**
   * this clears the list and deletes the keys
   */
  void clearAndDestroyKeys();
  /**
   * this clears the list and deletes the values
   */
  void clearAndDestroyValues();
  /**
   * this clears the list and deletes both the values and the keys
   */
  void clearAndDestroy();
  /**
   * this returns the number of entries in the table
   */
  USize entries() const;
  /**
   * destructor
   */
  virtual ~skHashTable();
 protected:
  /**
   * Constructor - makes the table an initial size
   */
  skHashTable(USize  size);
  /**
   * puts a new key and value into the table. If the key already exists, it is first deleted
   */
  void insertKeyAndValue(void * key, void * value);
  /**
   * returns the value associated with the given key
   */
  void *  value(void * key) const;
  /**
   * deletes both the key and the value associated with the given key
   */
  void del(void * key);
  /**
   * deletes the key but not the value associated with the given key
   */
  void delKeyNotValue(void * key);
  /**
   * removes the entry associated with the given key
   */
  void remove(void * key);
  /**
   * this method is overriden by derived classes and returns a hash value for the given key
   */
  virtual USize hashKey(void * key) const=0;
  /**
   * this method is overriden by derived classes and compares two key values
   */
  virtual int compareKeys(void * key1, void * key2) const=0;
  /**
   * this method is overriden by derived classes and deletes the given key object
   */
  virtual void deleteKey(void * key)=0; 
  /**
   * this method is overriden by derived classes and deletes the given value object
   */
  virtual void deleteValue(void * value)=0;
 private:
  /**
   * default constructor
   */
  skHashTable();
  /**
   * copy constructor is private to prevent copying
   */
  skHashTable(const skHashTable&);
  /**
   * assignment operator is private to prevent copying
   */
  skHashTable& operator=(const skHashTable&);
  /**
   * finds the entry containing the given key, and also returns the slot number
   */
  skHashEntry * findEntry(void * key,USize & slot) const;
  /**
   * finds the entry containing the given key
   */
  skHashEntry * findEntry(void * key) const;
  /**
   * an array of HashEntry lists
   */
  skHashEntryList * m_Slots;
  /**
   * the number of lists in the m_Slots array
   */
  USize m_Size;
  /**
   * the number of entries in the entire table
   */
  USize m_NumEntries;
  friend class skHashTableIterator;
};
/**
 * this class provides an iterator for the hashtable
 */
class  skHashTableIterator
{
 public:
  /**
   * destructor
   */
  virtual ~skHashTableIterator();
  /**
   * this function returns 1 if a value and key are available
   */
  int operator()();
 protected:
  /**
   * this contructor is protected and is overriden in derived classes
   */
  skHashTableIterator(const skHashTable&);
  /**
   * this returns the current key in the iteration - it is overriden in derived classes to provide type-safety
   */
  void * key() const; 
  /**
   * this returns the current value in the iteration - it is overriden in derived classes to provide type-safety
   */
  void * value() const;
 private:
  /**
   * the assignment operator is private to prevent copying
   */
  skHashTableIterator& operator=(const skHashTableIterator&);
  /**
   * a reference to the table being iterated over
   */
  const skHashTable& 	m_Table;
  /**
   * the current slot number in the iteration
   */
  USize  m_Slot;
  /**
   * the current value in the iteration
   */
  void * m_Value;
  /**
   * the current key
   */
  void * m_Key;
  /**
   * the current iterator over the hash entry list at the current slot
   */
  skHashEntryListIterator * m_ListIterator;
};
#define TT_PREFIX template <class TKey,class TValue> 

const int DEFAULT_skHashTable_SIZE=3;
/**
 * This class overrides the base class to provide type-safety
 */
template <class TKey,class TValue>  class  skTHashTable: public skHashTable
{
 public:
  /**
   * constructs the table with the given size
   */
  skTHashTable(USize  size);
  /**
   * default constructor which constructs a table with 3 entries
   */
  skTHashTable();
  /**
   * destructor - destroys the keys and values in the table
   */
  ~skTHashTable();
  /**
   * this method adds the given key and value to the table. If the key is already in the table, the existing version is first deleted
   */
  void insertKeyAndValue(TKey * key, TValue * value);
  /**
   * returns the value associated with the given key (or 0)
   */
  TValue * value(const TKey * key);
  /**
   * deletes the key and value from the table
   */
  void del(const TKey * key);
  /**
   * deletes the key but not the value from the table
   */
  void delKeyNotValue(const TKey * key);
  /**
   * removes but does not delete the value and key
   */
  void remove(const TKey * key);
    
 protected:
  /**
   * this method compares two instances of the key. It uses the == operator for the class
   */
  int compareKeys(void * key1, void * key2) const;
  /**
   * deletes the given key (casting it appropriately)
   */
  void deleteKey(void * key);
  /**
   * deletes the given value (casting it appropriately)
   */
  void deleteValue(void * value);
  /**
   * returns a hash value for the given key, calling a global function USize ::hashKey(TKey * key)
   */
  USize hashKey(void * key) const;
};
/**
 * This class provides a type-safe iterator for the templated hash table
 */
template <class TKey,class TValue>  class skTHashTableIterator: public skHashTableIterator
{
 public:
  /**
   * constructs the iterator referring to the given table
   */
  skTHashTableIterator(const skTHashTable<TKey,TValue>&);
  /**
   * returns the current key
   */
  TKey * key() const;
  /**
   * returns the current value
   */
  TValue * value() const;
};

#include "skHashTable.inl"

#endif
