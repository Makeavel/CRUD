package com.api.crud.service;

import java.util.List;

import org.springframework.stereotype.Service;

import com.api.crud.model.Usuario;
import com.api.crud.repository.UsuarioRepository;

import lombok.RequiredArgsConstructor;

@Service
@RequiredArgsConstructor
public class UsuarioServiceImpl implements UsuarioService{

    private final UsuarioRepository repository;

    public Usuario findPostCreate(Usuario user){
        return repository.save(user);
    }

    public List<Usuario> findGetReadAll(){
        return repository.findAll();
    }

    public Usuario findPutUser(Usuario user){
        return repository.save(user);
    }

    public Usuario findDeleteUser(String cpf){
        return null;
    }

}