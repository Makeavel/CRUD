package com.api.crud.service;

import java.util.List;

import com.api.crud.model.Usuario;

public interface UsuarioService{

    Usuario findPostCreate(Usuario user);

    List<Usuario> findGetReadAll();

    Usuario findPutUser(Usuario user);

    Usuario findDeleteUser(String cpf);

}