typedef struct Song{
        char *s_name;
        char *artist_name;
        struct Song *p_next;
    }Song;

    typedef struct playlist{
        struct Song *p_head;
    }playlist;