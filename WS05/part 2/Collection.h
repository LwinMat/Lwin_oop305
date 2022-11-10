#ifndef _SDDS_COLLECTION_H_
#define _SDDS_COLLECTION_H_
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>

namespace sdds
{
	template<typename T>

	class Collection
	{
		std::string m_name_collection = {};
		T* items = nullptr;
		size_t m_size = 0u;
		void(*m_collection_observer)(const Collection<T>&, const T&) = nullptr;
	public:
		Collection(const std::string& name) {
			this->m_name_collection = name;
			this->m_size = 0u;
			this->m_collection_observer = nullptr;
			this->items = nullptr;
		}

		Collection(const Collection& src) = delete;
		Collection operator=(const Collection&) = delete;

		// Destructor
		~Collection() {
			delete[] items;
		}

		const std::string& name() const {
			return this->m_name_collection;
		}

		size_t size() const {
			return this->m_size;
		}

		void setObserver(void (*observer)(const Collection<T>& collection, const T& type)) {
			this->m_collection_observer = observer;
		}

		Collection<T>& operator+=(const T& item) {
			bool same = false;
			for (auto i = 0u; i < this->m_size; i++) {
				if (this->items[i].title() == item.title()) {
					same = true;
				}
			}

			if (same == false) {

				T* temp = new T[this->m_size + 1u];
				for (auto i = 0u; i < this->m_size; ++i) {
					temp[i] = this->items[i];
				}
				temp[m_size] = item;


				delete[] this->items;

				this->items = temp;

				m_size += 1;



				if (this->m_collection_observer != nullptr) {
					m_collection_observer(*this, item);
				}
			}


			return *this;

			
		}

		T& operator[](size_t idx) const {
			if (idx > this->m_size - 1) {
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(this->m_size) + "] items.");
			}
			else {
				return items[idx];
			}
		}

		T* operator[](const std::string& title) const {

			for (size_t i = 0u; i < this->m_size; i++) {
				if (this->items[i].title() == title) {
					return &items[i];
				}
			}

			return nullptr;
		}

		friend std::ostream& operator<<(std::ostream& ostr, const Collection& collection) {
			for (size_t i = 0u; i < collection.m_size; i++) {
				ostr << collection.items[i];
			}

			return ostr;
		}
	};
}


#endif // !_SDDS_COLLECTION_H_
