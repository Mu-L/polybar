#pragma once

#include <mutex>

#include "common.hpp"

// fwd
struct _snd_ctl_elem_id;
struct _snd_ctl_elem_info;
struct _snd_ctl_elem_value;
struct _snd_ctl;
struct _snd_hctl_elem;
struct _snd_hctl;
typedef struct _snd_ctl_elem_id snd_ctl_elem_id_t;
typedef struct _snd_ctl_elem_info snd_ctl_elem_info_t;
typedef struct _snd_ctl_elem_value snd_ctl_elem_value_t;
typedef struct _snd_ctl snd_ctl_t;
typedef struct _snd_hctl_elem snd_hctl_elem_t;
typedef struct _snd_hctl snd_hctl_t;

POLYBAR_NS

namespace alsa {
  class control {
   public:
    explicit control(int numid);
    ~control();

    int get_numid();
    bool wait(int timeout = -1);
    bool test_device_plugged();
    void process_events();

   private:
    std::mutex m_lock;

    int m_numid{0};

    snd_hctl_t* m_hctl{nullptr};
    snd_hctl_elem_t* m_elem{nullptr};

    snd_ctl_t* m_ctl{nullptr};
    snd_ctl_elem_info_t* m_info{nullptr};
    snd_ctl_elem_value_t* m_value{nullptr};
    snd_ctl_elem_id_t* m_id{nullptr};
  };
}

POLYBAR_NS_END