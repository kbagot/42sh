/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 20:10:12 by kbagot            #+#    #+#             */
/*   Updated: 2017/11/01 23:50:39 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <fcntl.h>
# include <string.h>
# include <signal.h>
# include "env.h"
# include "history.h"
# include "ast.h"
# include "builtins.h"
# include "sys/wait.h"
# include "htable.h"
# define VRDF_APPEND 0x8
# define VRDF_STDERR 0x4
# define VRF_SKIP 0x1
# define VRF_LAST_KO 0x10
# define VRF_NEW_PATH 0x18

typedef struct		s_job
{
	int				idc;
	int				id;
	char			*name;
	int				status;
	int				dead;
	struct s_job	*next;
}					t_job;

typedef struct		s_vm
{
	t_hs			*hs;
	t_envent		*env;
	t_envent		*local;
	t_htbucket		*htable;
	t_ast			*ast;
	t_cmd			*work;
	int				reg;
	int				newpid;
	t_job			*job;
	char			*buffer;
}					t_vm;

typedef struct		s_sv
{
	int				dollar;
	char			*name;
}					t_sv;

void		vm_free(t_vm **vm);
t_vm		*vm_init(char **environ);
void		vm_loadast(t_vm *vm, t_ast *ast);
int			vm_readast(t_vm	*vm, t_ast *ast, int *out);
int			vm_isbuiltin(t_cmd *cmd, t_vm *vm, int *out);
int			vm_isextbuiltin(t_cmd *cmd);
void		vm_kill_cmds(t_cmd *cmd);

int			vm_fork_cmd(char *path, t_cmd *cmd, t_vm *vm,
int (*f)(t_cmd *cmd, int, t_vm *));
int			vm_fork(char *path, t_cmd *cmd, t_vm *vm,
int (*f)(t_cmd *cmd, int, t_vm *));
int			vm_fork_builtin(t_cmd *cmd, t_vm *vm,
int (*f)(t_cmd *cmd, int, t_vm *));

int			vm_fcb_piped(t_cmd *cmd, int pid, t_vm *vm);
int			vm_fcb_def(t_cmd *cmd, int pid, t_vm *vm);
int			vm_exec_redir(t_cmd *cmd, t_ast *redir, t_vm *vm);
int			vm_exec(t_cmd *cmd, int flags, t_vm *vm, int *out);

int			vm_exec_rdout(t_ast *rd);
int			vm_exec_rdin(t_ast *redir);
int			vm_open_dup(char *name, int fd, int flags);
void		vm_duplocals(t_envent *loc, t_token **toks);

void		ft_env(t_cmd *cmd, t_envent **ev, t_vm *vm, int *out);

void		ft_history(char **av, t_vm *vm, t_envent *env, int m);

void		ft_jobs(t_vm *vm);
void		ft_fg(char *arg, t_vm *vm);
void		ft_bg(char *arg, t_vm *vm);
void		tc_ign_exec();
void		add_job(int g_pid, t_vm *vm, int res);
void		del_job(int i, t_vm *vm);
void		clear_job(t_vm *vm);
void		update_jobs(t_vm *vm, int display);
void		display_status(t_job *i);

void        treat_var(char ***cmd, t_envent **locals, t_envent **env);
void		ft_set_var(char **t, t_envent **locals, t_envent **env);


#endif
