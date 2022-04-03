#ifndef DESK_INTERFACE_H
#define DESK_INTERFACE_H

class DeskInterface
{
    public:
        virtual unsigned get_id() const = 0;
        virtual unsigned return_new_id() const = 0;
        virtual void set_id() = 0;
        virtual ~DeskInterface() = 0;
};

#endif