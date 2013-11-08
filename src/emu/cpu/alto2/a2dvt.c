/*****************************************************************************
 *
 *   Portable Xerox AltoII display vertical task
 *
 *   Copyright: Juergen Buchmueller <pullmoll@t-online.de>
 *
 *   Licenses: MAME, GPLv2
 *
 *****************************************************************************/
#include "alto2.h"

/**
 * @brief f1_dvt_block early: disable the display word task
 */
void alto2_cpu_device::f1_dvt_block_0()
{
	m_task_wakeup &= ~(1 << m_task);
	LOG((0,2,"	BLOCK %s\n", task_name(m_task)));
}


/**
 * @brief called by the CPU when the display vertical task becomes active
 */
void alto2_cpu_device::activate_dvt()
{
	/* TODO: what do we do here? */
	m_task_wakeup &= ~(1 << m_task);
}

/**
 * @brief initialize display vertical task
 */
void alto2_cpu_device::init_dvt(int task)
{
	set_f1(task, f1_block,			&alto2_cpu_device::f1_dvt_block_0, 0);
	set_f2(task, f2_dvt_evenfield,	0, &alto2_cpu_device::f2_evenfield_1);
	m_active_callback[task] = &alto2_cpu_device::activate_dvt;
}
