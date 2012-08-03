#ifndef AUTO_GETSETTOOLS_H
#define AUTO_GETSETTOOLS_H

/* this is always the final macro so the terminating ; in the calling file
 * will properly terminate every experssion, allowing for more readable code.
 * IE: this deliberately doesn't have a trailing ';'
 */
#define _AUTO_TYPE(autotype, lcname)            \
    private:                                                \
         autotype m_ ## lcname
                                                            

#define _AUTO_GET(autotype, lcname)         \
    public:                                                 \
         const autotype &lcname() const {                   \
              return m_ ## lcname;                          \
         }                                                  \

#define _AUTO_SIGNAL(autotype, lcname)                      \
    signals:                                                \
        void lcname ## Changed();                           \

#define AUTO_GET(autotype, lcname)                          \
    Q_PROPERTY(autotype lcname READ lcname);                \
    _AUTO_GET(autotype, lcname)                             \
    _AUTO_TYPE(autotype, lcname)

#define AUTO_GET_WITH_SIGNAL(autotype, lcname)                        \
    Q_PROPERTY(autotype lcname READ lcname NOTIFY lcname ## Changed); \
    _AUTO_GET(autotype, lcname)                                       \
    _AUTO_SIGNAL(autotype, lcname)                                    \
    _AUTO_TYPE(autotype, lcname)


#define AUTO_GET_SET_NOTIFY(autotype, lcname, ucname)                   \
    Q_PROPERTY(autotype lcname READ lcname WRITE set ## ucname NOTIFY lcname ## Changed);                \
    _AUTO_GET(autotype, lcname)                                         \
    _AUTO_SIGNAL(autotype, lcname)                                      \
                                                                        \
    public slots:                                                       \
    void set ## ucname(const autotype &newval) {                        \
        if (newval != m_ ## lcname) {                                   \
            m_ ## lcname = newval;                                      \
            emit lcname ## Changed();                                   \
        }                                                               \
    }                                                                   \
                                                                        \
    _AUTO_TYPE(autotype, lcname)

#endif /* AUTO_GETSETTOOLS_H */
