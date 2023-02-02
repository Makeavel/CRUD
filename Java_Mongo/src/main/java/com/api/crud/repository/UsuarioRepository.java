package com.api.crud.repository;

import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.stereotype.Repository;

import com.api.crud.model.Usuario;

@Repository
public interface UsuarioRepository extends MongoRepository<Usuario , String>{
    
}