package com.example.ciprian.exam

import android.content.Intent
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.support.design.widget.Snackbar
import android.support.v7.widget.LinearLayoutManager
import android.support.v7.widget.RecyclerView
import android.view.View
import com.example.ciprian.exam.adapters.MainAdapter
import com.example.ciprian.exam.adapters.SecondAdapter
import kotlinx.android.synthetic.main.activity_first.*
import kotlinx.android.synthetic.main.activity_third.*

class ThirdActivity : AppCompatActivity(),MyCallback {
    var adapter: SecondAdapter? = null

    private var recyclerView: View? = null
    private var manager: Manager? = null
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_third)
        manager = Manager(application as MyApp)
        recyclerView = findViewById(R.id.users_list)
        setupRecyclerView(recyclerView as RecyclerView)
        loadEvents()
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        loadEvents()
    }

    fun loadEvents():Boolean{
        progressSecond.visibility = View.VISIBLE
        val connectivity = manager!!.networkConnectivity(applicationContext)
        if(!connectivity){
            showError("There is no connection")
        } else{
            manager!!.loadUsers(progressSecond,this,this)
        }

        return connectivity
    }
    override fun clear() {

    }

    override fun showError(message: String) {
        progressSecond.visibility = View.GONE
        Snackbar.make(recyclerView!!, message, Snackbar.LENGTH_INDEFINITE)
                .setAction("RETRY") { loadEvents() }.show()
    }

//    private fun setupRecyclerView(recyclerView: RecyclerView){
//        adapter = MainAdapter()
////        (application as MyApp).db.typeDao.types
////                .observe(this, Observer { bikes ->
////                    if (bikes != null) {
////                        //adapter!!.setData(bikes as MutableList<Type>,progressFirst,application as RateApp,this,this)
////                    }
////                })
//
//        recyclerView.layoutManager = LinearLayoutManager(this)
//        recyclerView.adapter = adapter
//    }

    private fun setupRecyclerView(recyclerView: RecyclerView){
        adapter = SecondAdapter()

        recyclerView.layoutManager = LinearLayoutManager(this)
        recyclerView.adapter = adapter
    }
}
