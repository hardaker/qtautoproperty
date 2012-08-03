#ifndef QTAUTO_PARAMETERS_H
#define QTAUTO_PARAMETERS_H

#ifndef _QTAUTO_OPERATE

/* replacement macros so you don't have to comment them out */

#define QTAUTO_GET(autotype, lcname)
#define QTAUTO_GET_SIGNAL(autotype, lcname)
#define QTAUTO_GET_SET_SIGNAL(autotype, lcname)
#define QTAUTO_HERE

#else 

/* this is always the final macro so the terminating ; in the calling file
 * will properly terminate every experssion, allowing for more readable code.
 * IE: this deliberately doesn't have a trailing ';'
 */
#define _QTAUTO_TYPE(autotype, lcname)            \
    private:                                                \
         autotype m_ ## lcname;
                                                            

#define _QTAUTO_GET(autotype, lcname)         \
    public:                                                 \
         const autotype &lcname() const {                   \
              return m_ ## lcname;                          \
         }                                                  \

#define _QTAUTO_SIGNAL(autotype, lcname)                      \
    signals:                                                \
        void lcname ## Changed();                           \

#define QTAUTO_GET(autotype, lcname)                          \
    Q_PROPERTY(autotype lcname READ lcname)                \
    _QTAUTO_GET(autotype, lcname)                             \
    _QTAUTO_TYPE(autotype, lcname)

#define QTAUTO_GET_SIGNAL(autotype, lcname)                        \
    Q_PROPERTY(autotype lcname READ lcname NOTIFY lcname ## Changed) \
    _QTAUTO_GET(autotype, lcname)                                       \
    _QTAUTO_SIGNAL(autotype, lcname)                                    \
    _QTAUTO_TYPE(autotype, lcname)


#define QTAUTO_GET_SET_SIGNAL(autotype, lcname, ucname)                   \
    Q_PROPERTY(autotype lcname READ lcname WRITE set ## ucname NOTIFY lcname ## Changed)                \
    _QTAUTO_GET(autotype, lcname)                                         \
    _QTAUTO_SIGNAL(autotype, lcname)                                      \
                                                                        \
    public slots:                                                       \
    void set ## ucname(const autotype &newval) {                        \
        if (newval != m_ ## lcname) {                                   \
            m_ ## lcname = newval;                                      \
            emit lcname ## Changed();                                   \
        }                                                               \
    }                                                                   \
                                                                        \
    _QTAUTO_TYPE(autotype, lcname)

#endif /* _QTAUTO_OPERATE */
#endif /* QTAUTO_PARAMETERS_H */
