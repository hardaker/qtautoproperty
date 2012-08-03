    AUTO_GET_SET_SIGNAL(int, myIntProperty);
//
AUTO_HERE
/* AGST */ Q_PROPERTY(int myIntProperty READ myIntProperty WRITE setMyIntProperty NOTIFY myIntPropertyChanged); public: const int &myIntProperty() const { return m_myIntProperty; } signals: void myIntPropertyChanged(); public slots: void setMyIntProperty(const int &newval) { if (newval != m_myIntProperty) { m_myIntProperty = newval; emit myIntPropertyChanged(); } } private: int m_myIntProperty
